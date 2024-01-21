#include "raylib.h"

int main(){

    // window dimensions
    int w{800};
    int h{450}; 
    InitWindow(w,h,"Big Window");

    //  circle coordinates
    int circ_x{200};
    int circ_y{200};
    int circ_rad{25};

    // circle edges
    int l_circ_x{circ_x - circ_rad};
    int r_Circ_x{circ_x + circ_rad};
    int u_circ_y{circ_y - circ_rad};
    int b_circ_y{circ_y + circ_rad};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_len{50};

    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_len};
    int u_axe_y{axe_y};
    int b_axe_Y{axe_y + axe_len};

    int direction{10};

    bool colided{true};

    SetTargetFPS(60);
    while(WindowShouldClose() != true){
        BeginDrawing();
        ClearBackground(WHITE);

        if (!colided){
            DrawText("YOU DIED.", 400, 200, 20, RED);
        }
        else{
            // game logic begins
            DrawCircle(circ_x, circ_y, circ_rad, BLUE);
            DrawRectangle(axe_x, axe_y, axe_len, axe_len, RED);

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
        }

        EndDrawing();
    };

}