#include "raylib.h"
int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe (rectangle) coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // axe (rectangle) edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};
    // direction is used in the game logic to move the axe
    int axe_direction_y{10};
    int axe_direction_x{-10};

    //start the game button
    bool start_game{false};
    // Collision conditions
    bool collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
          if (!start_game)
        {
            DrawText("Press SPACE to play the game", 200, 225, 20, RED);
            if (IsKeyDown(KEY_SPACE))
            {
                start_game = true;
            }
        }
        else
        {
        if (collision_with_axe)
        {
        DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic begins

            //update the circleand axe edges every frame
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            //update collision_with_axe every frame
            collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // move the axe
            axe_y += axe_direction_y;
            axe_x -= axe_direction_x;
            if (axe_y > height || axe_y < 0)
            {
                axe_direction_y = -axe_direction_y;
            }
            if (axe_x > width || axe_x < 0)
            {
                axe_direction_x = -axe_direction_x;
            }

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }   
              if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += 10;
            }
            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= 10;
            }  
            // Game logic ends
        }
        }
        EndDrawing();
    }
}
