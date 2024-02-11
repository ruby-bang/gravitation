#include "raylib.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HIEGHT 800
#define BALL_SIZE 50
#define LIMIT 60
#define FONTSIZE 60

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HIEGHT, "Gravitation");
  SetTargetFPS(60);
  int bx = 0 + BALL_SIZE;
  int by = SCREEN_HIEGHT / 2 + BALL_SIZE;
  float speedx = 10;
  float speedy = -150;
  float accx = 0.1;
  float accy = 0.1;
  int floor = 1;

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      int font_widht = MeasureText(
          TextFormat("X %d | Y %d | FLOOR  %d", bx, by, floor), FONTSIZE);

      DrawText(TextFormat("X %d | Y %d | FLOOR  %d", bx, by, floor),
               (SCREEN_WIDTH / 2) - (font_widht * 0.5),
               SCREEN_HIEGHT * 0.5 - FONTSIZE * 0.5, FONTSIZE, GRAY);

      if (bx >= SCREEN_WIDTH - BALL_SIZE || bx < 0 + BALL_SIZE) {
        accx += (accx + 0.5) * -1;
        speedx *= -1 + accx;
      }
      if (by < SCREEN_HIEGHT - BALL_SIZE && speedy <= LIMIT) {
        accy += 0.01;
        speedy += accy;
        bx += speedx;
      }

      if (by <= (SCREEN_HIEGHT - BALL_SIZE) && floor >= 1) {
        by += speedy;

        if (by <= 0) {
          floor += 1;
          by = SCREEN_HIEGHT - BALL_SIZE;
        }
        if (by >= SCREEN_HIEGHT - BALL_SIZE + 2 && floor > 1) {
          floor -= 1;
          by = 0;
        }
      }
      DrawCircle(bx, by, BALL_SIZE, RED);
    }
    EndDrawing();
  }
  CloseWindow();
}
