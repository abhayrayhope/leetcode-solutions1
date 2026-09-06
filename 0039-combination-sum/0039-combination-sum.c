/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 */

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize,
               int*** ans, int* returnSize, int** returnColumnSizes) {

    if (target == 0) {
        (*ans) = realloc((*ans), ((*returnSize) + 1) * sizeof(int*));
        (*returnColumnSizes) = realloc((*returnColumnSizes),
                                       ((*returnSize) + 1) * sizeof(int));

        (*ans)[*returnSize] = malloc(pathSize * sizeof(int));
        memcpy((*ans)[*returnSize], path, pathSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i,
                  path, pathSize + 1,
                  ans, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;
    *returnColumnSizes = NULL;

    int** ans = NULL;
    int path[100];

    backtrack(candidates, candidatesSize, target, 0,
              path, 0,
              &ans, returnSize, returnColumnSizes);

    return ans;
}