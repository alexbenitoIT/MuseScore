/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_NOTATION_INOTATIONPAINTING_H
#define MU_NOTATION_INOTATIONPAINTING_H

#include <memory>
#include "notationtypes.h"

#include "infrastructure/draw/painter.h"
#include "infrastructure/draw/paintdevice.h"

namespace mu::notation {
class INotationPainting
{
public:
    virtual ~INotationPainting() = default;

    struct Options
    {
        int fromPage = -1; // 0 is first
        int toPage = -1;
        int copyCount = 1;
        int trimMarginPixelSize = -1;
        int deviceDpi = -1;
    };

    virtual void setViewMode(const ViewMode& vm) = 0;
    virtual ViewMode viewMode() const = 0;

    virtual int pageCount() const = 0;
    virtual SizeF pageSizeInch() const = 0; // size in inches

    virtual void paintView(draw::Painter* painter, const RectF& frameRect) = 0;
    virtual void paintPublish(draw::Painter* painter, const RectF& frameRect) = 0;
    virtual void paintPdf(draw::PagedPaintDevice* dev, draw::Painter* painter, const Options& opt) = 0;
    virtual void paintPng(draw::Painter* painter, const Options& opt) = 0;
    virtual void paintPrint(draw::PagedPaintDevice* dev, draw::Painter* painter, const Options& opt) = 0;
};

using INotationPaintingPtr = std::shared_ptr<INotationPainting>;
}

#endif // MU_NOTATION_INOTATIONPAINTING_H
