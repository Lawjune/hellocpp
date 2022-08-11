# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Definition of matrix data structure
typedef struct {
    float *data;
    size_t nrows;
    size_t ncols;
} matrix;


// Initialization and clean-up for matrix
enum matrix_err_code
{
    MATRIX_SUCCESS,
    MATRIX_ERR_MEMORY_INSUFFICICENT,
    MATRIX_ERR_MISMATCHED_MATRIX_SIZE,
};

int matrix_alloc(matrix* ptr, size_t nrows, size_t ncols)
{
    size_t size = nrows * ncols * sizeof(float);
    float *data = malloc(size);

    if (data == NULL) {
        return MATRIX_ERR_MEMORY_INSUFFICICENT;
    }

    ptr->data = data;
    ptr->nrows = nrows;
    ptr->ncols = ncols;
}

void matrix_dealloc(matrix* ptr)
{
    if (ptr->data == NULL) {
        return;
    }
    free(ptr->data);
    ptr->data = NULL;
    ptr->nrows = 0;
    ptr->ncols = 0;
}


// Multiplication function
int matrix_multiply(matrix* result, const matrix* lhs, const matrix* rhs)
{
    int errcode;
    if (lhs->ncols != rhs->nrows) {
        return MATRIX_ERR_MISMATCHED_MATRIX_SIZE;
    }

    errcode = matrix_alloc(result, lhs->nrows, rhs->ncols);
    if (errcode != MATRIX_SUCCESS) {
        return errcode;
    }

    // Processing multiplication
    int i, j, k;
    for (i = 0; i < lhs->ncols; i++)
    {
        for (j = 0; j < rhs->ncols; j++) 
            result->data[i][j] = 0;
            for (k = 0; k < result->ncols; k++)
                result->data[i][j] += lhs->data[i][k] * rhs->data[k][j];
    }

        return MATRIX_SUCCESS;
}

int main()
{
    int errcode;
    matrix *a, *b, *c;

    memset(a, 0, sizeof(matrix));
    memset(b, 0, sizeof(matrix));
    memset(c, 0, sizeof(matrix));

    errcode = matrix_multiply(c, a, b);
    if (errcode != MATRIX_SUCCESS) {
        fprintf(stderr, "MATRIX ERROR: %d", errcode);
        matrix_dealloc(c);
        matrix_dealloc(a);
        matrix_dealloc(b);
        exit(1);
    }

    // Using multiplication result to do something

}