#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

struct plyn {
	int coeff;
	int power;
};

struct lnode *createPlynExpr(int coeff, int power);
struct lnode *insertPlynTerm(struct lnode **expr, int coeff, int power);

struct lnode *addPlynExpr(struct lnode *expr1, struct lnode *expr2);

void printExpr(struct lnode *expr);

int main(int argc, char *argv[]) 
{
	struct lnode *expr1 = createPlynExpr(2, 3);
	insertPlynTerm(&expr1, 8, 2);
	insertPlynTerm(&expr1, 16, 1);
	printf("first term:\t");
	printExpr(expr1);

	struct lnode *expr2 = createPlynExpr(4, 2);
	insertPlynTerm(&expr2, 16, 1);
	printf("second term:\t\t");
	printExpr(expr2);

	printf("\n");

	struct lnode *sum = addPlynExpr(expr1, expr2);
	printf("sum:\t\t");
	printExpr(sum);
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

	return sum;
}

void printExpr(struct lnode *expr)
{
	while (expr != NULL) {
		struct plyn *term = (struct plyn*)expr->data;
		if (expr->next != NULL) {
			printf("%dx^%d + ", term->coeff, term->power);
		} else {
			printf("%dx^%d", term->coeff, term->power);
		}
		expr = expr->next;
	}
	printf("\n");
}
