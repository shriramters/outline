
#include <vk_app.hpp>
#include <spdlog/spdlog.h>

void draw_canvas(skity::Canvas* canvas);
void highlight_cursor(skity::Canvas* canvas, float x, float y);

class App : public outline::VkApp {
public:
    App()
        : outline::VkApp(800, 600, "Outline", { 1.f, 1.f, 1.f, 1.f }) {}
    ~App() override = default;

    std::vector<skity::Path> paths = { skity::Path() };

protected:
    void OnUpdate(float elapsed_time) override {
        // get mouse position and draw circle
        double x, y;
        GetCursorPos(x, y);
        highlight_cursor(GetCanvas(), x, y);

        if (GetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {
            if (paths.back().countPoints() == 0)
            {
                spdlog::info("moveTo: {}, {}", x, y);
                paths.back().moveTo(x, y);
            }
            paths.back().lineTo(x, y);
        }

        if (!GetMouseButton(GLFW_MOUSE_BUTTON_LEFT) && paths.back().countPoints() > 0) {
            paths.emplace_back();
        }

        draw_canvas(GetCanvas());

        // draw all paths
        skity::Paint paint;
        paint.setStyle(skity::Paint::kStroke_Style);
        paint.setStrokeCap(skity::Paint::kRound_Cap);
        paint.setStrokeJoin(skity::Paint::kRound_Join);
        paint.setStrokeWidth(10.f);
        paint.setStrokeColor(0.f, 0.f, 0.f, 1.f);
        paint.setAntiAlias(true);

        for (const auto& path : paths) {
            GetCanvas()->drawPath(path, paint);
        }

        GetCanvas()->flush();
    }
};

int main(int argc, const char** argv) {
    App app;
    app.Run();
    return 0;
}