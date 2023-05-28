#ifndef _NNRT_H_
#define _NNRT_H_

#ifndef NNRT_FLOAT
#define NNRT_FLOAT float
#endif

#include <ctype.h>
#include <stdio.h>

typedef struct {
    NNRT_FLOAT *data;
    int *shape;
    int ndim;
} nnrt_Tensor;

void nnrt_affine(nnrt_Tensor *a, nnrt_Tensor *b, nnrt_Tensor *c,
                 nnrt_Tensor *out);
void nnrt_batchnorm_2d(nnrt_Tensor *a, int num_features,
                       float *gamma, float *shift, nnrt_Tensor *out);
void nnrt_conv_2d(nnrt_Tensor *a, nnrt_Tensor *kernel,
                  int stride, int pad, nnrt_Tensor *out);
void nnrt_matmul(nnrt_Tensor *a, nnrt_Tensor *b, nnrt_Tensor *out);
void nnrt_maxpool_2d(nnrt_Tensor *a, nnrt_Tensor *kernel,
                     int stride, int pad, nnrt_Tensor *out);

void nnrt_relu(nnrt_Tensor *a, nnrt_Tensor *out);
void nnrt_sigmoid(nnrt_Tensor *a, nnrt_Tensor *out);
void nnrt_argmax(nnrt_Tensor *a, int axis, nnrt_Tensor *out);
void nnrt_softmax(nnrt_Tensor *a, int axis, nnrt_Tensor *out);

nnrt_Tensor *nnrt_tensor_alloc(int ndim, int *shape);
nnrt_Tensor *nnrt_tensor_fread(FILE *fp);
size_t nnrt_tensor_size(nnrt_Tensor *t);
void nnrt_tensor_free(nnrt_Tensor *t);

#endif
