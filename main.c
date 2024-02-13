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
  float speedy = -50;
  float accx = 0.1;
  float accy = 0.1;
  int floor = 1;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    const char *Floor = TextFormat("FLOOR %d", floor);
    int font_widht = MeasureText(Floor, FONTSIZE);

    DrawText(Floor, (SCREEN_WIDTH * 0.5) - (font_widht * 0.5),
             (SCREEN_HIEGHT * 0.5) - (FONTSIZE * 0.5), FONTSIZE, GRAY);

    if (bx >= SCREEN_WIDTH - BALL_SIZE || bx < 0 + BALL_SIZE) {
      accx += (accx + 0.5) * -1;
      speedx *= -1 + accx;
    }
    if (by < SCREEN_HIEGHT - BALL_SIZE && speedy <= LIMIT)
      accy += 0.01, bx += speedx;

    else if (by >= SCREEN_HIEGHT - BALL_SIZE && speedy > 0 && floor == 1) {
      accy += (accy * 0.5) * -1;
      speedy *= -1 + accy;

      speedx *= -1 * 0.5;
    }
    speedy += accy;
    if (by <= (SCREEN_HIEGHT - BALL_SIZE) && floor >= 1) {

      by += speedy;
      if (speedy > 0 && speedy < 5 && floor == 1 &&
          by >= SCREEN_HIEGHT - BALL_SIZE - 20) {
        accy = 0;
        accx = 0;
        speedx = 0;
      }
      if (by <= 0)
        floor += 1, by = SCREEN_HIEGHT - BALL_SIZE;

      if (by >= SCREEN_HIEGHT - BALL_SIZE + 2 && floor > 1)
        floor -= 1, by = 0;
    } else {
      by += speedy;
    }
    DrawCircle(bx, by, BALL_SIZE, RED);
    EndDrawing();
  }
  CloseWindow();
}
