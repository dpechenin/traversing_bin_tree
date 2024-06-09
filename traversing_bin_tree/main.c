#include <stdio.h>
#include <stdlib.h>

typedef struct BinTree {
    int value;
    struct BinTree *left;
    struct BinTree *right;
} Tree;

Tree* addEl(int num, Tree *root) {
    if (root == NULL) {
        root = (Tree*)malloc(sizeof(Tree));
        root->value = num;
        root->left = root->right = NULL;
    }
    else if (num < root->value) {
        root->left = addEl(num, root->left);
    }
    else {
        root->right = addEl(num, root->right);
    }
    return root;
}

void freeTree(Tree *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        freeTree(root->left);
    }
}
// обходы в глубину
// прямой
void preOrderTravers(Tree *root) {
    if (root) {
        printf("%d ", root->value);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}
// симетричный или поперечный
void inOrderTravers(Tree *root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->value);
        inOrderTravers(root->right);
    }
}
// в обратном порядке
void postOrderTravers(Tree *root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    Tree *root = NULL;
    int a[] = {3, 2, 1, 0, 9, 5, 4, 7, 8, 6, 31, 42};
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        root = addEl(a[i], root);
    }
    printf("Прямой (pre-order): ");
    preOrderTravers(root);
    printf("\n");
    printf("Симметричный или поперечный (in-order): ");
    inOrderTravers(root);
    printf("\n");
    printf("В обратном порядке (post-order): ");
    postOrderTravers(root);
    printf("\n");
    freeTree(root);
    return 0;
}
