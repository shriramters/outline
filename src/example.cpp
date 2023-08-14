
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <skity/skity.hpp>
#include <string>

// same as https://fiddle.skia.org/c/@text_rendering
void draw_simple_text(skity::Canvas* canvas) {
    skity::Paint paint;

    paint.setTextSize(64.f);
    paint.setAntiAlias(true);
    paint.setFillColor(0x42 / 255.f, 0x85 / 255.f, 0xF4 / 255.f, 1.f);
    paint.setStyle(skity::Paint::kFill_Style);

    skity::TextBlobBuilder builder;
    paint.setTypeface(canvas->getDefaultTypeface());
    auto blob = builder.buildTextBlob("outline", paint);

    canvas->drawTextBlob(blob.get(), 20.f, 64.f, paint);

    paint.setStyle(skity::Paint::kStroke_Style);
    paint.setStrokeColor(0xDB / 255.f, 0x44 / 255.f, 0x37 / 255.f, 1.f);
    paint.setStrokeWidth(2.f);

    canvas->drawTextBlob(blob.get(), 20.f, 144.f, paint);

    paint.setFillColor(0x0F / 255.f, 0x9D / 255.f, 0x58 / 255.f, 1.f);
    paint.setStyle(skity::Paint::kFill_Style);

    canvas->save();

    skity::Vec4 colors[] = {
        skity::Vec4{0.f, 1.f, 1.f, 1.f},
        skity::Vec4{0.f, 0.f, 1.f, 1.f},
        skity::Vec4{1.f, 0.f, 0.f, 1.f},
    };

    std::vector<skity::Point> pts = {
        skity::Point{0.f, 0.f, 0.f, 1.f},
        skity::Point{200.f, 0.f, 0.f, 1.f},
    };

    auto lgs = skity::Shader::MakeLinear(pts.data(), colors, nullptr, 3);
    paint.setShader(lgs);

    canvas->drawTextBlob(blob.get(), 20.f, 224.f, paint);
    canvas->restore();
}

void draw_canvas(skity::Canvas* canvas) {
    canvas->save();
    canvas->translate(20, 0);
    draw_simple_text(canvas);
    canvas->restore();
}

void highlight_cursor(skity::Canvas* canvas, float x, float y) {
    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setFillColor(0x42 / 255.f, 0x85 / 255.f, 0xF4 / 255.f, 1.f);
    paint.setStyle(skity::Paint::kFill_Style);
    canvas->drawCircle(x, y, 20.f, paint);
}