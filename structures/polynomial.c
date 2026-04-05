/* 
    Write a C program to Define an Abstract Data Type (ADT) polynomial using
    nested structures concept and implement the following functions
    i) Initializing all terms of the polynomial as zeros
    ii) Appending each term of the polynomial
    iii) To perform addition between two polynomials
    iv) To display the polynomial 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50

// Structure for an individual term
typedef struct
{
    float coeff;
    int exp;
} Term;

// Nested structure for the Polynomial ADT
typedef struct
{
    Term terms[MAX_TERMS];
    int numTerms;
} Polynomial;

// i) Initializing all terms of the polynomial as zeros
void initPolynomial(Polynomial *p)
{
    p->numTerms = 0;
    for (int i = 0; i < MAX_TERMS; i++)
    {
        p->terms[i].coeff = 0.0;
        p->terms[i].exp = 0;
    }
}

// ii) Appending each term of the polynomial
void appendTerm(Polynomial *p, float coeff, int exp)
{
    if (p->numTerms >= MAX_TERMS)
    {
        printf("Error: Polynomial capacity reached.\n");
        return;
    }
    // Simple implementation: adds term to the end
    p->terms[p->numTerms].coeff = coeff;
    p->terms[p->numTerms].exp = exp;
    p->numTerms++;
}

// iv) To display the polynomial
void displayPolynomial(Polynomial p)
{
    if (p.numTerms == 0)
    {
        printf("0\n");
        return;
    }
    for (int i = 0; i < p.numTerms; i++)
    {
        printf("%.1fx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i < p.numTerms - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// iii) To perform addition between two polynomials
Polynomial addPolynomials(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    initPolynomial(&result);
    int i = 0, j = 0;

    // Standard merge-sort style addition for sorted exponents
    while (i < p1.numTerms && j < p2.numTerms)
    {
        if (p1.terms[i].exp > p2.terms[j].exp)
        {
            appendTerm(&result, p1.terms[i].coeff, p1.terms[i].exp);
            i++;
        } else if (p1.terms[i].exp < p2.terms[j].exp)
        {
            appendTerm(&result, p2.terms[j].coeff, p2.terms[j].exp);
            j++;
        } else {
            float sumCoeff = p1.terms[i].coeff + p2.terms[j].coeff;
            if (sumCoeff != 0)
            {
                appendTerm(&result, sumCoeff, p1.terms[i].exp);
            }
            i++;
            j++;
        }
    }

    // Append remaining terms
    while (i < p1.numTerms)
    {
        appendTerm(&result, p1.terms[i++].coeff, p1.terms[i].exp);
    }
    while (j < p2.numTerms)
    {
        appendTerm(&result, p2.terms[j++].coeff, p2.terms[j].exp);
    }
    

    return result;
}

int main()
{
    Polynomial poly1, poly2, sum;

    initPolynomial(&poly1);
    initPolynomial(&poly2);

    // Creating Poly 1: 5x^2 + 3x^1
    appendTerm(&poly1, 5, 2);
    appendTerm(&poly1, 3, 1);

    // Creating Poly 2: 4x^2 + 2x^0
    appendTerm(&poly2, 4, 2);
    appendTerm(&poly2, 2, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPolynomial(sum);

    return 0;
}