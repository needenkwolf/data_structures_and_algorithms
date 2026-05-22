#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#define MAX_COEFF 200

struct plyn {
	int coeff;
	int power;
};

struct lnode *insertPlynTerm(struct lnode **expr, int coeff, int power);

struct lnode *createPlynExpr(int coeff, int power);
struct lnode *simplifyPlynExpr(struct lnode **expr);
struct lnode *addPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *subPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *mulPlynExpr(struct lnode *expr1, struct lnode *expr2);
struct lnode *divPlynExpr(struct lnode *expr1, struct lnode *expr2);

void sortArray(int *array, int n);

void printExpr(struct lnode *expr);

#endif
