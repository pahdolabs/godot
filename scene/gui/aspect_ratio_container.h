/*************************************************************************/
/*  aspect_ratio_container.h                                             */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef ASPECT_RATIO_CONTAINER_H
#define ASPECT_RATIO_CONTAINER_H

#include "scene/gui/container.h"

class AspectRatioContainer : public Container {
	GDCLASS(AspectRatioContainer, Container);

protected:
	void _notification(int p_what);
	static void _bind_methods();
	virtual Size2 get_minimum_size() const;

public:
	enum StretchMode {
		STRETCH_WIDTH_CONTROLS_HEIGHT,
		STRETCH_HEIGHT_CONTROLS_WIDTH,
		STRETCH_FIT,
		STRETCH_COVER,
	};
	enum AlignMode {
		ALIGN_BEGIN,
		ALIGN_CENTER,
		ALIGN_END,
	};

private:
	float ratio = 1.0;
	float max_ratio = ratio;
	bool use_max_ratio = false;
	bool use_auto_size = false;
	float auto_size_extent = 1080.0f;
	StretchMode stretch_mode = STRETCH_FIT;
	AlignMode alignment_horizontal = ALIGN_CENTER;
	AlignMode alignment_vertical = ALIGN_CENTER;

public:
	void set_ratio(float p_ratio);
	float get_ratio() const { return ratio; }

	void set_max_ratio(float p_max_ratio);
	float get_max_ratio() const { return max_ratio; }

	void set_use_max_ratio(bool p_use_max_ratio);
	bool get_use_max_ratio() const { return use_max_ratio; }

	void set_use_auto_size(bool p_use_auto_size);
	bool get_use_auto_size() const { return use_auto_size; }

	void set_auto_size_extent(float p_auto_size_extents);
	float get_auto_size_extent() const { return auto_size_extent; }

	void set_stretch_mode(StretchMode p_mode);
	StretchMode get_stretch_mode() const { return stretch_mode; }

	void set_alignment_horizontal(AlignMode p_alignment_horizontal);
	AlignMode get_alignment_horizontal() const { return alignment_horizontal; }

	void set_alignment_vertical(AlignMode p_alignment_vertical);
	AlignMode get_alignment_vertical() const { return alignment_vertical; }
};

VARIANT_ENUM_CAST(AspectRatioContainer::StretchMode);
VARIANT_ENUM_CAST(AspectRatioContainer::AlignMode);

#endif // ASPECT_RATIO_CONTAINER_H
