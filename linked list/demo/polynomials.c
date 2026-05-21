#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

#define MAX_COEFF 200

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

void sortArray(int *array, int n);

void printExpr(struct lnode *expr);

int main(int argc, char *argv[]) 
{
	printf("\n");
	printf("--------------------------------\n");
	printf("PLEASE ENTER YOUR INPUT\n");
	printf("EXAMPLE:\t 4x^2\n");
	printf("EXAMPLE:\t 1x^1\n");
	printf("EXAMPLE:\t 8\n");
	printf("EXAMPLE:\t 0\n");
	printf("[OUTPUT]:\t 4x^2 + 1x^1 + 8\n");
	printf("--------------------------------\n");
	printf("\n");

	while (1) {
		struct lnode *expr1 = NULL;
		struct lnode *expr2 = NULL;
		int s1 = 1;
		int s2 = 1;
		int c = 1;
		int p = 0;
		while (c != 0 && s1 > 0) { 
			printf("[0 = DONE] input for first expr: ");
			s1 = scanf("%dx^%d", &c, &p);

			
			if (s1 <= 0) {
				scanf("%*[^\n]");
				c = 0;
				p = 0;
			} else if (s1 == 1) {
				p = 0;
			}

			if (c == 0) break;
			
			if (expr1 == NULL) {
				expr1 = createPlynExpr(c, p);
			} else {
				insertPlynTerm(&expr1, c, p);
			}
		}
		if (expr1 == NULL) return -1;

		printf("\nfirst expr:\t");
		simplifyPlynExpr(&expr1);
		printExpr(expr1);

		printf("\n");

		c = 1;
		p = 0;
		while (c != 0 && s2 > 0) {
			printf("[0 = DONE] input for second expr: ");
			s2 = scanf("%dx^%d", &c, &p);

			if (s2 <= 0) {
				scanf("%*[^\n]");
				c = 0;
				p = 0;
			} else if (s2 == 1) {
				p = 0;
			}

			if (c == 0) break;

			if (expr2 == NULL) {
				expr2 = createPlynExpr(c, p);
			} else {
				insertPlynTerm(&expr2, c, p);
			}
		}
		if (expr2 == NULL) return -1;
		printf("\nsecond expr:\t");
		simplifyPlynExpr(&expr2);
		printExpr(expr2);


		struct plyn *term1 = (struct plyn*)expr1->data;
		struct plyn *term2 = (struct plyn*)expr2->data;
		if (term1->coeff == 0 || term2->coeff == 0) return -1;

		printf("\n");

		struct lnode *sum = addPlynExpr(expr1, expr2);
		printf("sum:\t\t");
		printExpr(sum);

		struct lnode *sub = subPlynExpr(expr1, expr2);
		printf("sub:\t\t");
		printExpr(sub);

		struct lnode *mul = mulPlynExpr(expr1, expr2);
		printf("mul:\t\t");
		if (mul == NULL) {
			printf("unsupported\n");
		} else {
			printExpr(mul);
		}

		struct lnode *div = divPlynExpr(expr1, expr2);
		printf("div:\t\t");
		if (div == NULL) {
			printf("not possible to divide\n");
		} else {
			printExpr(div);
		}
		printf("--------------------------------\n");
		printf("\n");

		freeList(&expr1);
		freeList(&expr2);
	}
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

/*	function to add polynomials expressions
 *	works as intended for most polynomials
 *	probably won't change much in the future
*/
struct lnode *addPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *sum = NULL;

	struct lnode *p = expr1;
	struct lnode *q = expr2;
	while (p != NULL && q != NULL) {
		struct plyn *term1 = (struct plyn*)p->data;
		struct plyn *term2 = (struct plyn*)q->data;

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
				p = p->next;
				continue;
			} else {
				if (sum == NULL) {
					sum = createPlynExpr(term2->coeff, term2->power);
				} else {
					insertPlynTerm(&sum, term2->coeff, term2->power);
				}
				q = q->next;
				continue;
			}
		}
		p = p->next;
		q = q->next;
	}
	while (p != NULL && sum != NULL) {
		struct plyn *term1 = (struct plyn*)p->data;
		insertPlynTerm(&sum, term1->coeff, term1->power);
		p = p->next;
	}
	while (q != NULL && sum != NULL) {
		struct plyn *term2 = (struct plyn*)q->data;
		insertPlynTerm(&sum, term2->coeff, term2->power);
		q = q->next;
	}
	simplifyPlynExpr(&sum);
	return sum;
}

/*	function to subtract polynomials expressions
 *	works as intended for most polynomials
 *	might be optimized yet
*/
struct lnode *subPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	if (expr1 == NULL || expr2 == NULL) return NULL;

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

/*	function to multiply a polynomial expression
 *	works as intended for most polynomials
*/
struct lnode *mulPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *mul = NULL;

	struct lnode *p = expr1;
	struct lnode *q = expr2;
	while (p != NULL && q != NULL) {
		struct plyn *term1 = (struct plyn*)p->data;
		struct plyn *term2 = (struct plyn*)q->data;

		int coeff = term1->coeff * term2->coeff;
		int power = term1->power + term2->power;

		if (mul == NULL) {
			mul = createPlynExpr(coeff, power);
		} else {
			insertPlynTerm(&mul, coeff, power);
		}
		p = p->next;
		if (p == NULL && q != NULL) {
			p = expr1;
			q = q->next;
			continue;
		} 
	}
	simplifyPlynExpr(&mul);
	return mul;
}

/* 	w.i.p function to divide a polynomial expression
 *  	not fully supported yet (20/05/2026)
 *  	
*/
struct lnode *divPlynExpr(struct lnode *expr1, struct lnode *expr2)
{
	struct lnode *div = NULL;
	struct lnode *mul = NULL;
	struct lnode *sub = NULL;
	struct lnode *tosub = NULL;

	int i = 1;
	int found = 0;
	struct lnode *p = expr1;
	struct lnode *q = expr2;
	while (p != NULL && q != NULL && found == 0) {
		struct plyn *term1 = (struct plyn*)p->data;
		struct plyn *term2 = (struct plyn*)q->data;

		if (i == 1) {
			if ((term1->coeff % term2->coeff) != 0) break;
			int coeff = term1->coeff / term2->coeff;
			int power = term1->power - term2->power;
			
			if (div == NULL) {
				div = createPlynExpr(coeff, power);
			}
		} else {
			if (tosub == NULL) {
				tosub = expr1;
			} else {
				tosub = sub;
			}
			if (mul != NULL) freeList(&mul);

			struct lnode *divp = div;
			while (divp->next != NULL) {
				divp = divp->next;
			}

			mul = mulPlynExpr(expr2, divp);
			if (mul == NULL) return NULL;

			sub = subPlynExpr(tosub, mul);
 
			struct plyn *subterm = NULL;
			struct lnode *subp = NULL;
			if (sub != NULL) {
				subterm = (struct plyn*)sub->data;
				subp = sub;
			}

			found = 1;
			while (subp != NULL) {
				struct plyn *subterm2 = (struct plyn*)subp->data;
				if (subterm2->coeff != 0) {
					found = 0;
				}
				subp = subp->next;
			}
			if (found == 1) break;
			
			if ((subterm->coeff % term2->coeff) != 0) break;
			int coeff = subterm->coeff / term2->coeff;
			int power = subterm->power - term2->power;
			insertPlynTerm(&div, coeff, power);
		}
		i++;
	}
	freeList(&mul);
	freeList(&sub);
	if (found == 0) {
		freeList(&div);
		return NULL;
	}
	simplifyPlynExpr(&div);
	return div;
}

/*	w.i.p function to simplify polynomial expressions
 *	as of now, it works fine if exponents are in decreasing order and have close values
 *	will not work if it doesn't have these conditions
 *	currently working on fixing that
*/
struct lnode *simplifyPlynExpr(struct lnode **expr)
{
	/*
	int i = 1;
	struct lnode *p = *expr;
	struct plyn *data = (struct plyn*)p->data;
	struct lnode *smpl_expr = NULL;

	int biggest_pow = data->power;
	while (p != NULL) {
		struct plyn *data = (struct plyn*)p->data;
		if (biggest_pow < data->power) {
			biggest_pow = data->power;
		}
		p = p->next;
		i++;
	}
	p = *expr;

	int *pow_arr = malloc(sizeof(int) * MAX_COEFF);
	int *coeff_arr = malloc(sizeof(int) * MAX_COEFF);

	i = 0;
	p = *expr;
	while (p != NULL) {
		data = (struct plyn*)p->data;
		pow_arr[i] = data->power;
		p = p->next;
		i++;
	}

	int size = i;

	sortArray(pow_arr, MAX_COEFF);

	p = *expr;
	while (p != NULL) {
		i = 0;
		data = (struct plyn*)p->data;
		while (i != MAX_COEFF) {
			if (data->power == pow_arr[i]) {
				coeff_arr[i] += data->coeff;
			}
			i++;
		}
		p = p->next;
	}

	sortArray(coeff_arr, MAX_COEFF);

	i = 0;
	p = *expr;
	while (p != NULL && i < size) {
		if (smpl_expr == NULL)
			smpl_expr = createPlynExpr(coeff_arr[i], pow_arr[i]);
		else
			insertPlynTerm(&smpl_expr, coeff_arr[i], pow_arr[i]);
		
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
			i = 1;
			continue;
		}
		p = p->next;
		i++;
	}

	freeList(expr);
	*expr = smpl_expr;
	return smpl_expr;
	*/
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
			i = 1;
			continue;
		}
		p = p->next;
		i++;
	}

	freeList(expr);
	*expr = smpl_expr;
	return smpl_expr;
}

void sortArray(int *array, int n) 
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] < array[j + 1]) {
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
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
