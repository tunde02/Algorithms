// not yet

// #include <iostream>
// using namespace std;

// int r, c;

// int getSquare(char* rooms, int x, int y) {
//     int length = 1;
//     int i = 0;
//     bool isContinue = true;
//     bool isShared = true;
// cout << "start (" << x << ", " << y << ")\n";
//     while(isContinue) {
//         for(i = 0; i<length+1; i++) {
//             if(x + length >= r || y + length >= c) {
//                 isContinue = false;
//                 break;
//             }

//             cout << "check (" << x + length << ", " << y + i << ")";
//             cout << ", (" << x + i << ", " << y + length << ") ";

//             if((rooms[r*(x + length) + (y + i)] == 'x' || rooms[r*(x + length) + (y + i)] == 's')
//                 && (rooms[r*(x + i) + (y + length)] == 'x' || rooms[r*(x + i) + (y + length)] == 's'))
//             {
//                 cout << "success : [" << rooms[r*(x + length) + (y + i)] << ", " << rooms[r*(x + i) + (y + length)] << "]";
//                 if(rooms[r*(x + length) + (y + i)] == 'x'
//                     || rooms[r*(x + i) + (y + length)] == 'x') {
//                     isShared = false;
//                 }
//             }
//             else// if(rooms[r*(x + length) + (y + i)] == '.' || rooms[r*(x + i) + (y + length)] == '.')
//             {
//                 cout << "fail : [" << rooms[r*(x + length) + (y + i)] << ", " << rooms[r*(x + i) + (y + length)] << "]";
//                 isContinue = false;
//                 break;
//             }
//             // cout << "correct! ";
//         }

//         if(!isContinue)
//             break;

//         for(i--; i>=0; i--) {
//             cout << "remove (" << x + length << ", " << y + i << ")";
//             cout << ", (" << x + i << ", " << y + length << ") ";
//             rooms[r*(x + length) + (y + i)] = 's';
//             rooms[r*(x + i) + (y + length)] = 's';
//         }
// cout << endl;
//         length++;
//     }
// cout << endl;
//     return isShared ? -1 : length;
// }

// void print(char* rooms) {
//     for(int i=0; i<r; i++) {
//         for(int j=0; j<c; j++) {
//             cout << rooms[r*i + j];
//         }
//         cout << "\n";
//     }
// }

// int main() {
//     cin >> r >> c;
//     char rooms[r][c];

//     for(int i=0; i<r; i++) {
//         for(int j=0; j<c; j++) {
//             cin >> rooms[i][j];
//         }
//     }
// print(rooms[0]); // rooms�� ũ�⺸�� ū �ʱⰪ�� ������ �ָ��ϰ�
//     for(int i=0; i<r; i++) {
//         for(int j=0; j<c; j++) {
//             if(rooms[i][j] == 'x' || rooms[i][j] == 's') {
//                 rooms[i][j] = 's';
//                 int length = getSquare(rooms[0], i, j);
//                 if(length != -1) {
//                     cout << "\n" << i + 1 << " " << j + 1 << " " << length << "\n";
//                 }
//                 print(rooms[0]);
//             }
//         }
//     }
// }
#include <iostream>
using namespace std;

int r, c;

int getSquare(char* rooms, int x, int y) {
    int length = 1;
    int i = 0;
    bool isContinue = true;
    bool isShared = true;
    
    while(isContinue) {
        for(i = 0; i<length+1; i++) {
            if(x + length >= r || y + length >= c) {
                isContinue = false;
                break;
            }
            
            if((rooms[r*(x + length) + (y + i)] == 'x' || rooms[r*(x + length) + (y + i)] == 's')
                && (rooms[r*(x + i) + (y + length)] == 'x' || rooms[r*(x + i) + (y + length)] == 's'))
            {
                if(rooms[r*(x + length) + (y + i)] == 'x'
                    || rooms[r*(x + i) + (y + length)] == 'x') {
                    isShared = false;
                }
            }
            else
            {
                isContinue = false;
                break;
            }
        }

        if(!isContinue)
            break;

        for(i--; i>=0; i--) {
            rooms[r*(x + length) + (y + i)] = 's';
            rooms[r*(x + i) + (y + length)] = 's';
        }
        
        length++;
    }
    
    return isShared ? -1 : length;
}

int main() {
    cin >> r >> c;
    char rooms[r][c];

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> rooms[i][j];
        }
    }
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(rooms[i][j] == 'x' || rooms[i][j] == 's') {
                rooms[i][j] = 's';
                int length = getSquare(rooms[0], i, j);
                if(length != -1) {
                    cout << i + 1 << " " << j + 1 << " " << length << "\n";
                }
            }
        }
    }
}