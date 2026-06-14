#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "polynomials.h"

int main(int argc, char *argv[]) 
{
	printf("\n--------------------------------\n");
	printf("PLEASE ENTER YOUR INPUT\n");
	printf("EXAMPLE:\t 4x^2\n");
	printf("EXAMPLE:\t 1x^1\n");
	printf("EXAMPLE:\t 8\n");
	printf("EXAMPLE:\t 0\n");
	printf("[OUTPUT]:\t 4x^2 + 1x^1 + 8\n");
	printf("\n--------------------------------\n");

	while (1) {
		struct lnode *expr1 = NULL;
		struct lnode *expr2 = NULL;

		struct llist *list1 = malloc(sizeof(struct llist));
		list1->head = NULL;
		list1->tail = NULL;

		struct llist *list2 = malloc(sizeof(struct llist));
		list1->head = NULL;
		list1->tail = NULL;

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
				list1->head = expr1;
				list1->tail = expr1;
			} else {
				list1->tail = insertPlynTerm(&(list1->tail), c, p);
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
				list2->head = expr2;
				list2->tail = expr2;
			} else {
				list2->tail = insertPlynTerm(&(list2->tail), c, p);
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
