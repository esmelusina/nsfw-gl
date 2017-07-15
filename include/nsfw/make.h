#pragma once

#include "fwd.h"

Geometry makeGeometry(const Vertex * verts, size_t nverts, const unsigned * idxes, size_t nidx);
bool freeGeometry(Geometry &g);

Shader makeShader(const char *vsource, const char *fsource, unsigned long long flags);
bool freeShader(Shader &s);