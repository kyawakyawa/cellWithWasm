
void resetField(int* color, int width, int height) {
    int n = width;
    int cell[n][n];
    int a = 98432;
    int x = 4321;
    int p = 9999991;
    for (int i = 0; i < n; i++) {
        for(int j = 0;j < n;j++){
            //cell[i][j] = (i * j - i + j * 1000003) % 5;
            cell[i][j] = x % 5;
            x = (x + a) % p;
            color[i * n + j] = cell[i][j % 2 == 0] ? 0xffff0000 : 0xffffffff;
            switch (cell[i][j]){
                case 0 :
                    //glColor3d(0.5, 0.0, 1.0);
                    color[i * n + j] = 0xffff008f;
                    break;
                case 1 :
                    //glColor3d(0.0, 0.0, 1.0);
                    color[i * n + j] = 0xffff0000;
                    break;
                case 2 :
                    //glColor3d(0.0, 1.0, 0.0);
                    color[i * n + j] = 0xff00ff00;
                    break;
                case 3 :
                    //glColor3d(1.0, 1.0, 0.0);
                    color[i * n + j] = 0xff00ffff;
                    break;
                case 4 :
                    //glColor3d(1.0, 0.0, 0.0);
                    color[i * n + j] = 0x0000ff;
                    break;
            }
        }

    }
}

void nextCell(int *color,int n){
    int cell[n][n];
    int cell2[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            switch(color[i * n + j]){
                case 0xffff008f :
                    cell2[i][j] = cell[i][j] = 0;
                    break;
                case 0xffff0000:
                    cell2[i][j] = cell[i][j] = 1;
                    break;
                case 0xff00ff00 :
                    cell2[i][j] = cell[i][j] = 2;
                    break;
                case 0xff00ffff :
                    cell2[i][j] = cell[i][j] = 3;
                    break;
                case 0x0000ff:
                    cell2[i][j] = cell[i][j] = 4;
                    break;
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int count = 0;int val = (cell2[i][j] + 1) % 5;
            for(int k = -2;k < 3;k++){
                for(int l = -2;l < 3;l++){
                    if(cell2[(i + k + n) % n][(j + l + n) % n] == val)
                        count++;
                }
            }
            if(count >= 6)cell[i][j] = (cell2[i][j] + 1) % 5;
            //cell[i][j] = 1;//(cell2[i][j] + 1) % 5;
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0;j < n;j++){
            switch (cell[i][j]){
                case 0 :
                    //glColor3d(0.5, 0.0, 1.0);
                    color[i * n + j] = 0xffff008f;
                    break;
                case 1 :
                    //glColor3d(0.0, 0.0, 1.0);
                    color[i * n + j] = 0xffff0000;
                    break;
                case 2 :
                    //glColor3d(0.0, 1.0, 0.0);
                    color[i * n + j] = 0xff00ff00;
                    break;
                case 3 :
                    //glColor3d(1.0, 1.0, 0.0);
                    color[i * n + j] = 0xff00ffff;
                    break;
                case 4 :
                    //glColor3d(1.0, 0.0, 0.0);
                    color[i * n + j] = 0x0000ff;
                    break;
            }
        }
    }
}

/*
enum Direction {
    LEFT = 0,
    UP,
    RIGHT,
    DOWN
} direction = LEFT;

int ant(int* start, int width, int height, int position) {
    if (start[position] == 0xff000000) {
        start[position] = 0xffffffff;
        direction = (direction + 1) % 4;
    } else {
        start[position] = 0xff000000;
        direction = (direction + 3) % 4;
    }
    switch (direction) {
        case LEFT:
            return (position % width > 0) ? position - 1 : position + width - 1;
            break;
        case UP:
            return (position > width) ? position - width : position + width * (height - 1);
            break;
        case RIGHT:
            return (position % width < width - 1) ? position + 1 : position - width + 1;
            break;
        case DOWN:
            return (position < width * (height - 1)) ? position + width : position % width;
            break;
        default:
            return position;
            break;
    }
}*/
