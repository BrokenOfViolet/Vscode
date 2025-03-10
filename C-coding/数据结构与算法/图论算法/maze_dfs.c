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

// 记录路径的二维数组
bool visited[ROWS][COLS];

// 方向数组，用于控制上、下、左、右四个方向的移动
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 判断是否越界或者是否是障碍物
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0 && !visited[row][col]);
}

// 深度优先搜索
bool dfs(int row, int col) {
    // 如果到达终点
    if (row == ROWS - 1 && col == COLS - 1) {
        visited[row][col] = true;
        return true;
    }

    // 标记当前位置已访问
    visited[row][col] = true;

    // 逐个尝试四个方向
    for (int i = 0; i < 4; i++) {
        int newRow = row + dir[i][0];
        int newCol = col + dir[i][1];
        
        // 判断新位置是否有效
        if (isValid(newRow, newCol)) {
            // 递归搜索
            if (dfs(newRow, newCol)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    if (dfs(0, 0)) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }

    return 0;
}
