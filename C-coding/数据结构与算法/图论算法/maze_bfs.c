#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// 迷宫地图
int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

// 方向数组，用于控制上、下、左、右四个方向的移动
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 记录路径的二维数组
int path[ROWS][COLS];

// 判断是否越界或者是否是障碍物
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0 && path[row][col] == 0);
}

// 广度优先搜索
bool bfs(int startRow, int startCol, int endRow, int endCol) {
    // 初始化路径数组
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            path[i][j] = 0;
        }
    }

    // 定义队列用于BFS搜索
    int queue[ROWS * COLS][2];
    int front = 0, rear = 0;

    // 将起点加入队列
    queue[rear][0] = startRow;
    queue[rear][1] = startCol;
    rear++;

    // 标记起点已访问
    path[startRow][startCol] = 1;

    // BFS搜索
    while (front != rear) {
        int row = queue[front][0];
        int col = queue[front][1];
        front++;

        // 到达终点
        if (row == endRow && col == endCol) {
            return true;
        }

        // 尝试四个方向移动
        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            
            // 判断新位置是否有效
            if (isValid(newRow, newCol)) {
                queue[rear][0] = newRow;
                queue[rear][1] = newCol;
                rear++;
                path[newRow][newCol] = 1; // 标记新位置已访问
            }
        }
    }

    return false; // 无法找到路径
}

int main() {
    int startRow = 0, startCol = 0;
    int endRow = ROWS - 1, endCol = COLS - 1;

    if (bfs(startRow, startCol, endRow, endCol)) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }

    return 0;
}
