#pragma once

#include "fwd.h"

void draw(const Framebuffer &, const Shader &, const Geometry &);

void clear(const Framebuffer &f, float r = .2f, float g = .2f, float b = .2f, float a = .2f, bool doC = true, bool doB = true);