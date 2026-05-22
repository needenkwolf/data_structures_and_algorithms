#include <stdio.h>
#include <stdlib.h>
#include "../../list.h"
#include "polynomials.h"

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

	struct llist *sum_list = malloc(sizeof(struct llist));
	sum_list->head = NULL;
	sum_list->tail = NULL;

	struct lnode *p = expr1;
	struct lnode *q = expr2;
	while (p != NULL && q != NULL) {
		struct plyn *term1 = (struct plyn*)p->data;
		struct plyn *term2 = (struct plyn*)q->data;

		if (term1->power == term2->power) {
			int res = term1->coeff + term2->coeff;
			if (sum == NULL) {
				sum = createPlynExpr(res, term1->power);
				sum_list->head = sum;
				sum_list->tail = sum;
			} else {
				sum_list->tail = insertPlynTerm(&(sum_list->tail), res, term1->power);
			}
		} else {
			if (term1->power > term2->power) {
				if (sum == NULL) {
					sum = createPlynExpr(term1->coeff, term1->power);
					sum_list->head = sum;
					sum_list->tail = sum;
				} else {
					sum_list->tail = insertPlynTerm(&(sum_list->tail), term1->coeff, term1->power);
				}
				p = p->next;
				continue;
			} else {
				if (sum == NULL) {
					sum = createPlynExpr(term2->coeff, term2->power);
					sum_list->head = sum;
					sum_list->tail = sum;
				} else {
					sum_list->tail = insertPlynTerm(&(sum_list->tail), term2->coeff, term2->power);
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
		sum_list->tail = insertPlynTerm(&(sum_list->tail), term1->coeff, term1->power);
		p = p->next;
	}
	while (q != NULL && sum != NULL) {
		struct plyn *term2 = (struct plyn*)q->data;
		insertPlynTerm(&(sum_list->tail), term2->coeff, term2->power);
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

	struct llist *mul_list = malloc(sizeof(struct llist));
	mul_list->head = NULL;
	mul_list->tail = NULL;

	struct lnode *p = expr1;
	struct lnode *q = expr2;
	while (p != NULL && q != NULL) {
		struct plyn *term1 = (struct plyn*)p->data;
		struct plyn *term2 = (struct plyn*)q->data;

		int coeff = term1->coeff * term2->coeff;
		int power = term1->power + term2->power;

		if (mul == NULL) {
			mul = createPlynExpr(coeff, power);
			mul_list->head = mul;
			mul_list->tail = mul;
		} else {
			mul_list->tail = insertPlynTerm(&(mul_list->tail), coeff, power);
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

	struct llist *div_list = malloc(sizeof(struct llist));
	div_list->head = NULL;
	div_list->tail = NULL;

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
				div_list->head = div;
				div_list->tail = div;
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
			div_list->tail = insertPlynTerm(&(div_list->tail), coeff, power);
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
	int i = 1;
	struct lnode *p = *expr;
	struct plyn *data = (struct plyn*)p->data;
	struct lnode *smpl_expr = NULL;

	struct llist *smpl_list = malloc(sizeof(struct llist));
	smpl_list->head = NULL;
	smpl_list->tail = NULL;

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
		if (smpl_expr == NULL) {
			smpl_expr = createPlynExpr(coeff_arr[i], biggest_pow - i);
			smpl_list->head = smpl_expr;
			smpl_list->tail = smpl_expr;
		}
		else {
			smpl_list->tail = insertPlynTerm(&(smpl_list->tail), coeff_arr[i], biggest_pow - i);
		}
		
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
