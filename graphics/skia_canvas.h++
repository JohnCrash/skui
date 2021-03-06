/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Ruben Van Boxem
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/

/*
 * Graphics canvas for Skia.
 */

#ifndef SKUI_GRAPHICS_SKIA_CANVAS_H
#define SKUI_GRAPHICS_SKIA_CANVAS_H

#include <core/debug.h++>

#include "canvas.h++"

#include "size.h++"

#include <GrGLInterface.h>

#include <SkSurface.h>

#include <vector>

namespace skui
{
  namespace graphics
  {
    namespace implementation
    {
      void set_gradient(SkPaint& paint, const gradient& gradient);
    }
    class skia_canvas : public canvas
    {
    public:
      skia_canvas(const pixel_size& size,
                  const GrGLInterface& gl_interface,
                  canvas_flags flags);
      ~skia_canvas() override = default;

      void draw(const color& background_color) override;
      void draw(const rectangle& rectangle) override;
      void draw(const ellipse& ellipse) override;
      void draw(const label& label) override;
      void draw(const path& path) override;

    private:
      std::vector<SkPaint> make_paint(const shape& shape) const;
      SkPaint make_border_paint(const shape& shape) const;
      SkPaint make_fill_paint(const shape& shape) const;
      void set_gradient(SkPaint& paint, const gradient& gradient) const;


      sk_sp<GrContext> gr_context;
      sk_sp<SkSurface> surface;
    };
  }
}

#endif
