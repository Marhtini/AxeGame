#include "raylib.h"

int main(){

    // window dimensions
    int w{800};
    int h{450}; 
    InitWindow(w,h,"Big Window");

    //  circle coordinates
    int circ_x{200};
    int circ_y{200};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};

    int direction{10};

    SetTargetFPS(60);
    while(WindowShouldClose() != true){
        BeginDrawing();
        ClearBackground(WHITE);

        // game logic begins
        DrawCircle(circ_x, circ_y, 25, BLUE);
        DrawRectangle(axe_x, axe_y, 50, 50, RED);

        // move the axe
        axe_y += direction;
        if(axe_y > h || axe_y < 0){
            direction = -direction;
        }

        if (IsKeyDown(KEY_D) && circ_x < w){
            circ_x += 10;
        }

        if (IsKeyDown(KEY_A) && circ_x > 0){
            circ_x -= 10;
        }

        if (IsKeyDown(KEY_S) && circ_y < h){
            circ_y += 10;
        }

        if (IsKeyDown(KEY_W) && circ_y > 0){
            circ_y -= 10;
        }

        EndDrawing();
    };

}