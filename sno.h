/*	@(#)sno.h	1.1	*/
#include <stdio.h>

struct  node {
        struct node *p1;
        struct node *p2;
#ifdef gcos
	int typ;
	int ch;
#else
        char typ;
        char ch;
#endif
};

extern int     freesize;
extern struct  node *lookf;
extern struct  node *looks;
extern struct  node *lookend;
extern struct  node *lookstart;
extern struct  node *lookdef;
extern struct  node *lookret;
extern struct  node *lookfret;
extern int     cfail;
extern int     rfail;
extern struct  node *freelist, *freespace;
extern struct  node *namelist;
extern int     lc;
extern struct  node *schar;
/*
struct node *strst1(), *salloc(), *look(), *copy(), *sgetc(),
	*binstr(), *pop(), *doop(), *push(), *search(),
	*add(), *sub(), *mult(), *div(), *cat(),
	*compile(), *execute(), *eval(), *syspit();
*/
/* sno1.c */
struct node *init(char *s, int t);
int main(int argc, char *argv[]);
struct node *syspit(void);
void syspot(struct node *string);
struct node *strst1(char s[]);
int class(int c);
struct node *salloc(void);
void sfree(struct node *pointer);
int nfree(void);
struct node *look(struct node *string);
struct node *copy(struct node *string);
int equal(struct node *string1, struct node *string2);
int strbin(struct node *string);
struct node *binstr(int binary);
struct node *add(register struct node *string1, register struct node *string2);
struct node *sub(register struct node *string1, register struct node *string2);
struct node *mult(register struct node *string1, register struct node *string2);
struct node *sdiv(register struct node *string1, register struct node *string2);
struct node *cat(struct node *string1, struct node *string2);
struct node *dcat(struct node *a, struct node *b);
void delete(struct node *string);
void sysput(struct node *string);
void dump(void);
void dump1(struct node *base);
void writes(char *s);
struct node *sgetc(void);
void ncinit(int argc, char *argv[]);
void ncswitch(void);
char nextchar(void);
/* sno2.c */
struct node *compon(void);
struct node *nscomp(void);
struct node *push(struct node *stack);
struct node *pop(struct node *stack);
struct node *expr(struct node *start, int eof, struct node *e);
struct node *match(struct node *start, struct node *m);
struct node *compile(void);
/* sno3.c */
int bextend(struct node *str, struct node *last);
int ubextend(struct node *str, struct node *last);
struct node *search(struct node *arg, struct node *r);
/* sno4.c */
struct node *and(struct node *ptr);
struct node *eval(struct node *e, int t);
struct node *doop(int op, struct node *arg1, struct node *arg2);
struct node *execute(struct node *e);
void assign(struct node *adr, struct node *val);

