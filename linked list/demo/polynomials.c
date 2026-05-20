#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

#define MAX_COEFF 20

struct plyn {
	int coeff;
	int power;
};

struct lnode *createPlynExpr(int coeff, int power);
struct lnode *insertPlynTerm(struct lnode **expr, int coeff, int power);

struct lnode *addPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *subPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *mulPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *divPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *simplifyPlynExpr(struct lnode **expr);

void printExpr(struct lnode *expr);

int main(int argc, char *argv[]) 
{
	struct lnode *expr1 = createPlynExpr(9, 3);
	insertPlynTerm(&expr1, 6, 2);
	/*
	insertPlynTerm(&expr1, 8, 3);
	insertPlynTerm(&expr1, 16, 1);
	insertPlynTerm(&expr1, 9, 0);
	*/
	printf("first expr:\t");
	printExpr(expr1);

	struct lnode *expr2 = createPlynExpr(3, 2);
	/*
	insertPlynTerm(&expr2, 16, 1);
	insertPlynTerm(&expr2, 9, 0);
	*/
	printf("second expr:\t");
	printExpr(expr2);

	printf("\n");

	struct lnode *sum = addPlynExpr(expr1, expr2);
	printf("sum:\t\t");
	printExpr(sum);

	struct lnode *sub = subPlynExpr(expr1, expr2);
	printf("sub:\t\t");
	printExpr(sub);

	struct lnode *mul = mulPlynExpr(expr1, expr2);
	printf("mul:\t\t");
	printExpr(mul);

	struct lnode *div = divPlynExpr(expr1, expr2);
	printf("div:\t\t");
	printExpr(div);
	return 0;
}

struct lnode *createPlynExpr(int coeff, int power)
{
	struct plyn *expr = malloc(sizeof(struct plyn));
	expr->coeff = coeff;
	expr->power = power;
	return createLnode((void*)expr);
}

struct lnode *insertPlynTerm(struct lnode **expr, int coeff, int power)
{
	struct plyn *term = malloc(sizeof(struct plyn));
	term->coeff = coeff;
	term->power = power;
	return insertAtLend(expr, (void*)term);
}

struct lnode *addPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *sum = NULL;
	while (expr1 != NULL && expr2 != NULL) {
		struct plyn *term1 = (struct plyn*)expr1->data;
		struct plyn *term2 = (struct plyn*)expr2->data;

		if (term1->power == term2->power) {
			int res = term1->coeff + term2->coeff;
			if (sum == NULL) {
				sum = createPlynExpr(res, term1->power);
			} else {
				insertPlynTerm(&sum, res, term1->power);
			}
		} else {
			if (term1->power > term2->power) {
				if (sum == NULL) {
					sum = createPlynExpr(term1->coeff, term1->power);
				} else {
					insertPlynTerm(&sum, term1->coeff, term1->power);
				}
				expr1 = expr1->next;
				continue;
			} else {
				if (sum == NULL) {
					sum = createPlynExpr(term2->coeff, term2->power);
				} else {
					insertPlynTerm(&sum, term2->coeff, term2->power);
				}
				expr2 = expr2->next;
				continue;
			}
		}
		
		expr1 = expr1->next;
		expr2 = expr2->next;
	}
	simplifyPlynExpr(&sum);
	return sum;
}

struct lnode *subPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *p = expr2;
	while (p != NULL) {
		struct plyn *term2 = (struct plyn*)p->data;
		term2->coeff = -term2->coeff;
		p = p->next;
	}

	struct lnode *sub = addPlynExpr(expr1, expr2);

	p = expr2;
	while (p != NULL) {
		struct plyn *term2 = (struct plyn*)p->data;
		term2->coeff = -term2->coeff;
		p = p->next;
	}
	return sub;
}

struct lnode *mulPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *mul = NULL;

	while (expr1 != NULL && expr2 != NULL) {
		struct plyn *term1 = (struct plyn*)expr1->data;
		struct plyn *term2 = (struct plyn*)expr2->data;

		if (term1->power >= term2->power) {
			int coeff = term1->coeff * term2->coeff;
			int power = term1->power + term2->power;

			if (mul == NULL) {
				mul = createPlynExpr(coeff, power);
			} else {
				insertPlynTerm(&mul, coeff, power);
			}

			expr1 = expr1->next;
			continue;
		}

		expr1 = expr1->next;
		expr2 = expr2->next;
	}
	
	return mul;
}

struct lnode *divPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *div = NULL;

	while (expr1 != NULL && expr2 != NULL) {
		struct plyn *term1 = (struct plyn*)expr1->data;
		struct plyn *term2 = (struct plyn*)expr2->data;
	
		if (term1->power >= term2->power) {
			int coeff = term1->coeff / term2->coeff;
			int power = term1->power - term2->power;

			if (div == NULL) {
				div = createPlynExpr(coeff, power);
			} else {
				insertPlynTerm(&div, coeff, power);
			}

			expr1 = expr1->next;
			continue;
		}
		expr1 = expr1->next;
		expr2 = expr2->next;
	}

	return div;
}

struct lnode *simplifyPlynExpr(struct lnode **expr)
{
	int i = 1;
	struct lnode *p = *expr;
	struct plyn *data = (struct plyn*)p->data;
	struct lnode *smpl_expr = NULL;

	int biggest_pow = data->power;

	int *coeff_arr = malloc(sizeof(int) * MAX_COEFF);


	for (i = 0; i < MAX_COEFF; i++) {
		p = *expr;
		while (p != NULL) {
			data = (struct plyn*)p->data;
			if (data->power == (biggest_pow - i)) {
				coeff_arr[i] += data->coeff;
			}
			p = p->next;
		}
	}

	i = 0;
	p = *expr;
	while (p != NULL) {
		if (smpl_expr == NULL)
			smpl_expr = createPlynExpr(coeff_arr[i], biggest_pow - i);
		else 
			insertPlynTerm(&smpl_expr, coeff_arr[i], biggest_pow - i);
		
		p = p->next;
		i++;
	}

	i = 1;
	p = smpl_expr;
	while (p != NULL) {
		data = (struct plyn*)p->data;
		if (data->coeff == 0) {
			deleteAtLpos(&smpl_expr, i);
			p = smpl_expr;
			continue;
		}
		p = p->next;
		i++;
	}

	freeList(expr);
	*expr = smpl_expr;
	return smpl_expr;
}

void printExpr(struct lnode *expr)
{
	int i = 0;
	while (expr != NULL) {
		struct plyn *term = (struct plyn*)expr->data;
		int coeffrepr = 0;
		if (i == 0) {
			coeffrepr = term->coeff;
		} else {
			coeffrepr = ((term->coeff) > 0 ? term->coeff : -term->coeff);
		}
		if (expr->next != NULL) {
			char sign = (((struct plyn*)expr->next->data)->coeff > 0) ? '+' : '-';
			switch (term->power) {
				case 0:
					printf("%d %c ", coeffrepr, sign);
					break;
				case 1:
					printf("%dx %c ", coeffrepr, sign);
					break;
				default:
					printf("%dx^%d %c ", coeffrepr, term->power, sign);
					break;
			}
		} else {
			switch (term->power) {
				case 0:
					printf("%d", coeffrepr, term->coeff);
					break;
				case 1:
					printf("%dx", coeffrepr, term->coeff);
					break;
				default:
					printf("%dx^%d", coeffrepr, term->power);
					break;
			}
		}
		expr = expr->next;
		i++;
	}
	printf("\n");
}
