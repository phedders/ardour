// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_DRAWABLE_H
#define _GDKMM_DRAWABLE_H

#include <glibmm.h>

/* $Id$ */

/* Copyright (C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gdk/gdkdrawable.h>
#include <gdk/gdkrgb.h>
#include <pangomm/font.h>
#include <pangomm/layout.h>
#include <pangomm/layoutline.h>
#include <pangomm/glyphstring.h>
#include <gdkmm/gc.h>
#include <gdkmm/image.h>
#include <gdkmm/color.h>
#include <gdkmm/region.h>
#include <gdkmm/rgbcmap.h>
#include <gdkmm/types.h>
//#include <gdkmm/pixbuf.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkDrawable GdkDrawable;
typedef struct _GdkDrawableClass GdkDrawableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{ class Drawable_Class; } // namespace Gdk
namespace Gdk
{


/** @addtogroup gdkmmEnums Enums and Flags */

/**
 * @ingroup gdkmmEnums
 */
enum RgbDither
{
  RGB_DITHER_NONE,
  RGB_DITHER_NORMAL,
  RGB_DITHER_MAX
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::RgbDither> : public Glib::Value_Enum<Gdk::RgbDither>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{


class GC;
class Pixbuf;

/** Drawing Primitives.
 * Gdk::Drawable is the base class for all of the objects that accept drawing
 * commands.  The available drawables include pixmaps, windows, and bitmaps.
 * Drawable is abstract as there is no such type on the server side.
 *
 * To use a drawable, create a concrete Drawable of the type you wish to use
 * and a Gdk::GC (graphics context) for that Drawable.  With the GC you can
 * draw lines, text, arcs and such.
 */

class Drawable : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Drawable CppObjectType;
  typedef Drawable_Class CppClassType;
  typedef GdkDrawable BaseObjectType;
  typedef GdkDrawableClass BaseClassType;

private:  friend class Drawable_Class;
  static CppClassType drawable_class_;

private:
  // noncopyable
  Drawable(const Drawable&);
  Drawable& operator=(const Drawable&);

protected:
  explicit Drawable(const Glib::ConstructParams& construct_params);
  explicit Drawable(GdkDrawable* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Drawable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkDrawable*       gobj()       { return reinterpret_cast<GdkDrawable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkDrawable* gobj() const { return reinterpret_cast<GdkDrawable*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkDrawable* gobj_copy();

private:

  
protected:
  Drawable();

public:
  
  static Glib::RefPtr<Drawable> create();


  /** Fills * @a width  and * @a height  with the size of @a drawable .
   *  @a width  or @a height  can be <tt>0</tt> if you only want the other one.
   * 
   * On the X11 platform, if @a drawable  is a Gdk::Window, the returned
   * size is the size reported in the most-recently-processed configure
   * event, rather than the current size on the X server.
   * @param width Location to store drawable's width, or <tt>0</tt>.
   * @param height Location to store drawable's height, or <tt>0</tt>.
   */
  void get_size(int& width, int& height);
  
  /** Obtains the bit depth of the drawable, that is, the number of bits
   * that make up a pixel in the drawable's visual. Examples are 8 bits
   * per pixel, 24 bits per pixel, etc.
   * @return Number of bits per pixel.
   */
  int get_depth() const;

  
  /** Sets the colormap associated with @a drawable . Normally this will
   * happen automatically when the drawable is created; you only need to
   * use this function if the drawable-creating function did not have a
   * way to determine the colormap, and you then use drawable operations
   * that require a colormap. The colormap for all drawables and
   * graphics contexts you intend to use together should match. i.e.
   * when using a Gdk::GC to draw to a drawable, or copying one drawable
   * to another, the colormaps should match.
   * @param colormap A Gdk::Colormap.
   */
  void set_colormap(const Glib::RefPtr<Colormap>& colormap);
  
  /** Gets the colormap for @a drawable , if one is set; returns
   * <tt>0</tt> otherwise.
   * @return The colormap, or <tt>0</tt>.
   */
  Glib::RefPtr<Colormap> get_colormap();
  
  /** Gets the Gdk::Visual describing the pixel format of @a drawable .
   * @return A Gdk::Visual.
   */
  Glib::RefPtr<Visual> get_visual();

  
  /** Draws a point, using the foreground color and other attributes of 
   * the Gdk::GC.
   * @param gc A Gdk::GC.
   * @param x The x coordinate of the point.
   * @param y The y coordinate of the point.
   */
  void draw_point(const Glib::RefPtr<const GC>& gc, int x, int y);
  void draw_points(const Glib::RefPtr<const GC>& gc, const Glib::ArrayHandle<Point>& points);

  
  /** Draws a line, using the foreground color and other attributes of 
   * the Gdk::GC.
   * @param gc A Gdk::GC.
   * @param x1 The x coordinate of the start point.
   * @param y1 The y coordinate of the start point.
   * @param x2 The x coordinate of the end point.
   * @param y2 The y coordinate of the end point.
   */
  void draw_line(const Glib::RefPtr<const GC>& gc, int x1, int y1, int x2, int y2);
  void draw_lines(const Glib::RefPtr<const GC>& gc, const Glib::ArrayHandle<Point>& points);

  
  /** Draws a rectangular outline or filled rectangle, using the foreground color
   * and other attributes of the Gdk::GC.
   * 
   * A rectangle drawn filled is 1 pixel smaller in both dimensions than a 
   * rectangle outlined. Calling 
   * <tt>gdk_draw_rectangle (window, gc, <tt>true</tt>, 0, 0, 20, 20)</tt> 
   * results in a filled rectangle 20 pixels wide and 20 pixels high. Calling
   * <tt>gdk_draw_rectangle (window, gc, <tt>false</tt>, 0, 0, 20, 20)</tt> 
   * results in an outlined rectangle with corners at (0, 0), (0, 20), (20, 20),
   * and (20, 0), which makes it 21 pixels wide and 21 pixels high.
   * @param gc A Gdk::GC.
   * @param filled <tt>true</tt> if the rectangle should be filled.
   * @param x The x coordinate of the left edge of the rectangle.
   * @param y The y coordinate of the top edge of the rectangle.
   * @param width The width of the rectangle.
   * @param height The height of the rectangle.
   */
  void draw_rectangle(const Glib::RefPtr<const GC>& gc, bool filled, int x, int y, int width, int height);
  
  /** Draws an arc or a filled 'pie slice'. The arc is defined by the bounding
   * rectangle of the entire ellipse, and the start and end angles of the part 
   * of the ellipse to be drawn.
   * @param gc A Gdk::GC.
   * @param filled <tt>true</tt> if the arc should be filled, producing a 'pie slice'.
   * @param x The x coordinate of the left edge of the bounding rectangle.
   * @param y The y coordinate of the top edge of the bounding rectangle.
   * @param width The width of the bounding rectangle.
   * @param height The height of the bounding rectangle.
   * @param angle1 The start angle of the arc, relative to the 3 o'clock position,
   * counter-clockwise, in 1/64ths of a degree.
   * @param angle2 The end angle of the arc, relative to @a angle1 , in 1/64ths 
   * of a degree.
   */
  void draw_arc(const Glib::RefPtr<const GC>& gc, bool filled, int x, int y, int width, int height, int angle1, int angle2);
  void draw_polygon(const Glib::RefPtr<const GC>& gc, bool filled, const Glib::ArrayHandle<Point>& points);

  
  /** Copies the @a width  x @a height  region of @a src  at coordinates ( @a xsrc ,
   *  @a ysrc ) to coordinates ( @a xdest , @a ydest ) in @a drawable .
   *  @a width  and/or @a height  may be given as -1, in which case the entire
   *  @a src  drawable will be copied.
   * 
   * Most fields in @a gc  are not used for this operation, but notably the
   * clip mask or clip region will be honored.
   * 
   * The source and destination drawables must have the same visual and
   * colormap, or errors will result. (On X11, failure to match
   * visual/colormap results in a BadMatch error from the X server.)
   * A common cause of this problem is an attempt to draw a bitmap to
   * a color drawable. The way to draw a bitmap is to set the
   * bitmap as a clip mask on your Gdk::GC, then use gdk_draw_rectangle()
   * to draw a rectangle clipped to the bitmap.
   * @param gc A Gdk::GC sharing the drawable's visual and colormap.
   * @param src The source Gdk::Drawable, which may be the same as @a drawable .
   * @param xsrc X position in @a src  of rectangle to draw.
   * @param ysrc Y position in @a src  of rectangle to draw.
   * @param xdest X position in @a drawable  where the rectangle should be drawn.
   * @param ydest Y position in @a drawable  where the rectangle should be drawn.
   * @param width Width of rectangle to draw, or -1 for entire @a src  width.
   * @param height Height of rectangle to draw, or -1 for entire @a src  height.
   */
  void draw_drawable(const Glib::RefPtr<const GC>& gc, const Glib::RefPtr<const Drawable>& src, int xsrc, int ysrc, int xdest, int ydest, int width = -1, int height = -1);
  
  /** Draws a Gdk::Image onto a drawable.
   * The depth of the Gdk::Image must match the depth of the Gdk::Drawable.
   * @param gc A Gdk::GC.
   * @param image The Gdk::Image to draw.
   * @param xsrc The left edge of the source rectangle within @a image .
   * @param ysrc The top of the source rectangle within @a image .
   * @param xdest The x coordinate of the destination within @a drawable .
   * @param ydest The y coordinate of the destination within @a drawable .
   * @param width The width of the area to be copied, or -1 to make the area 
   * extend to the right edge of @a image .
   * @param height The height of the area to be copied, or -1 to make the area 
   * extend to the bottom edge of @a image .
   */
  void draw_image(const Glib::RefPtr<const GC>& gc, const Glib::RefPtr<const Image>& image, int xsrc, int ysrc, int xdest, int ydest, int width = -1, int height = -1);

  //segs is an array, and this function will be used so little that it doesn't seem worth wrapping it to use a container of C++ types.
  
  /** Draws a number of unconnected lines.
   * @param gc A Gdk::GC.
   * @param segs An array of Gdk::Segment structures specifying the start and 
   * end points of the lines to be drawn.
   * @param nsegs The number of line segments to draw, i.e. the size of the 
   *  @a segs  array.
   */
  void draw_segments(const Glib::RefPtr<const GC>& gc, GdkSegment* segs, int nsegs); // TODO

  //glyphs is not an array. I went down to pango_xft_render in pango and saw that PangoGlyphString here is not an array. -Bryan
  
  /** This is a low-level function; 99% of text rendering should be done
   * using gdk_draw_layout() instead.
   * 
   * A glyph is a single image in a font. This function draws a sequence of
   * glyphs.  To obtain a sequence of glyphs you have to understand a
   * lot about internationalized text handling, which you don't want to
   * understand; thus, use gdk_draw_layout() instead of this function,
   * gdk_draw_layout() handles the details.
   * @param gc A Gdk::GC.
   * @param font Font to be used.
   * @param x X coordinate of baseline origin.
   * @param y Y coordinate of baseline origin.
   * @param glyphs The glyph string to draw.
   */
  void draw_glyphs(const Glib::RefPtr<const GC>& gc, const Glib::RefPtr<const Pango::Font>& font, int x, int y, const Pango::GlyphString& glyphs);

  
  /** Render a Pango::LayoutLine onto an GDK drawable
   * 
   * If the layout's Pango::Context has a transformation matrix set, then
   *  @a x  and @a y  specify the position of the left edge of the baseline
   * (left is in before-tranform user coordinates) in after-transform
   * device coordinates.
   * @param gc Base graphics to use.
   * @param x The x position of start of string (in pixels).
   * @param y The y position of baseline (in pixels).
   * @param line A Pango::LayoutLine.
   */
  void draw_layout_line(const Glib::RefPtr<const GC>& gc, int x, int y, const Glib::RefPtr<const Pango::LayoutLine>& line);
  
  /** Render a Pango::LayoutLine onto a Gdk::Drawable, overriding the
   * layout's normal colors with @a foreground  and/or @a background .
   *  @a foreground  and @a background  need not be allocated.
   * 
   * If the layout's Pango::Context has a transformation matrix set, then
   *  @a x  and @a y  specify the position of the left edge of the baseline
   * (left is in before-tranform user coordinates) in after-transform
   * device coordinates.
   * @param gc Base graphics to use.
   * @param x The x position of start of string (in pixels).
   * @param y The y position of baseline (in pixels).
   * @param line A Pango::LayoutLine.
   * @param foreground Foreground override color, or <tt>0</tt> for none.
   * @param background Background override color, or <tt>0</tt> for none.
   */
  void draw_layout_line(const Glib::RefPtr<const GC>& gc, int x, int y, const Glib::RefPtr<const Pango::LayoutLine>& line, const Color& foreground, const Color& background);

  
  /** Render a Pango::Layout onto a GDK drawable
   * 
   * If the layout's Pango::Context has a transformation matrix set, then
   *  @a x  and @a y  specify the position of the top left corner of the
   * bounding box (in device space) of the transformed layout.
   * 
   * If you're using GTK+, the usual way to obtain a Pango::Layout
   * is gtk_widget_create_pango_layout().
   * @param gc Base graphics context to use.
   * @param x The X position of the left of the layout (in pixels).
   * @param y The Y position of the top of the layout (in pixels).
   * @param layout A Pango::Layout.
   */
  void draw_layout(const Glib::RefPtr<const GC>& gc, int x, int y, const Glib::RefPtr<const Pango::Layout>& layout);
  
  /** Render a Pango::Layout onto a Gdk::Drawable, overriding the
   * layout's normal colors with @a foreground  and/or @a background .
   *  @a foreground  and @a background  need not be allocated.
   * 
   * If the layout's Pango::Context has a transformation matrix set, then
   *  @a x  and @a y  specify the position of the top left corner of the
   * bounding box (in device space) of the transformed layout.
   * 
   * If you're using GTK+, the ususal way to obtain a Pango::Layout
   * is gtk_widget_create_pango_layout().
   * @param gc Base graphics context to use.
   * @param x The X position of the left of the layout (in pixels).
   * @param y The Y position of the top of the layout (in pixels).
   * @param layout A Pango::Layout.
   * @param foreground Foreground override color, or <tt>0</tt> for none.
   * @param background Background override color, or <tt>0</tt> for none.
   */
  void draw_layout(const Glib::RefPtr<const GC>& gc, int x, int y, const Glib::RefPtr<const Pango::Layout>& layout, const Color& foreground, const Color& background);

  
  /** Renders a rectangular portion of a pixbuf to a drawable.  The destination
   * drawable must have a colormap. All windows have a colormap, however, pixmaps
   * only have colormap by default if they were created with a non-<tt>0</tt> window 
   * argument. Otherwise a colormap must be set on them with 
   * Gdk::Drawable::set_colormap().
   * 
   * On older X servers, rendering pixbufs with an alpha channel involves round 
   * trips to the X server, and may be somewhat slow.
   * 
   * The clip mask of @a gc  is ignored, but clip rectangles and clip regions work
   * fine.
   * 
   * Since: 2.2
   * @param gc A Gdk::GC, used for clipping, or <tt>0</tt>.
   * @param pixbuf A Gdk::Pixbuf.
   * @param src_x Source X coordinate within pixbuf.
   * @param src_y Source Y coordinates within pixbuf.
   * @param dest_x Destination X coordinate within drawable.
   * @param dest_y Destination Y coordinate within drawable.
   * @param width Width of region to render, in pixels, or -1 to use pixbuf width.
   * @param height Height of region to render, in pixels, or -1 to use pixbuf height.
   * @param dither Dithering mode for Gdk::RGB.
   * @param x_dither X offset for dither.
   * @param y_dither Y offset for dither.
   */
  void draw_pixbuf(const Glib::RefPtr<const GC>& gc, const Glib::RefPtr<Pixbuf>& pixbuf,
    int src_x, int src_y, int dest_x, int dest_y,
    int width, int height,
    RgbDither dither, int x_dither, int y_dither);

  // Note: This has no 'refreturn' because get_image() returns a newly created Image object.
  
  /** A Gdk::Image stores client-side image data (pixels). In contrast,
   * Gdk::Pixmap and Gdk::Window are server-side
   * objects. get_image() obtains the pixels from a
   * server-side drawable as a client-side Gdk::Image.  The format of a
   * Gdk::Image depends on the Gdk::Visual of the current display, which
   * makes manipulating Gdk::Image extremely difficult; therefore, in
   * most cases you should use Gdk::Pixbuf::get_from_drawable() instead of
   * this lower-level function. A Gdk::Pixbuf contains image data in a
   * canonicalized RGB format, rather than a display-dependent format.
   * Of course, there's a convenience vs. speed tradeoff here, so you'll
   * want to think about what makes sense for your application.
   * 
   *  @a x , @a y , @a width , and @a height  define the region of @a drawable  to
   * obtain as an image.
   * 
   * You would usually copy image data to the client side if you intend
   * to examine the values of individual pixels, for example to darken
   * an image or add a red tint. It would be prohibitively slow to
   * make a round-trip request to the windowing system for each pixel,
   * so instead you get all of them at once, modify them, then copy
   * them all back at once.
   * 
   * If the X server or other windowing system backend is on the local
   * machine, this function may use shared memory to avoid copying
   * the image data.
   * 
   * If the source drawable is a Gdk::Window and partially offscreen
   * or obscured, then the obscured portions of the returned image
   * will contain undefined data.
   * @param x X coordinate on @a drawable .
   * @param y Y coordinate on @a drawable .
   * @param width Width of region to get.
   * @param height Height or region to get.
   * @return A Gdk::Image containing the contents of @a drawable .
   */
  Glib::RefPtr<Image> get_image(int x, int y, int width, int height) const;

  // gdk_drawable_copy_to_image() returns a new GdkImage when the image parameter is NULL, but that seems to be much the
  // same as gdk_drawable_get_image().
  void copy_to_image(const Glib::RefPtr<Image>& image, int src_x, int src_y, int dest_x, int dest_y, int width, int height) const;
  
  
  /** Computes the region of a drawable that potentially can be written
   * to by drawing primitives. This region will not take into account
   * the clip region for the GC, and may also not take into account
   * other factors such as if the window is obscured by other windows,
   * but no area outside of this region will be affected by drawing
   * primitives.
   * @return A Gdk::Region. This must be freed with gdk_region_destroy()
   * when you are done.
   */
  Region get_clip_region() const;
  
  /** Computes the region of a drawable that is potentially visible.
   * This does not necessarily take into account if the window is
   * obscured by other windows, but no area outside of this region
   * is visible.
   * @return A Gdk::Region. This must be freed with gdk_region_destroy()
   * when you are done.
   */
  Region get_visible_region() const;


  // **** RGB stuff ****

  
  void draw_rgb_image(
                   const Glib::RefPtr<const GC>& gc,
                   int x, int y, int width, int height,
                   RgbDither dith, const guchar* rgb_buf, int rowstride);

  
  void draw_rgb_image_dithalign(
                   const Glib::RefPtr<const GC>& gc,
                   int x, int y, int width, int height,
                   RgbDither dith, const guchar* rgb_buf, int rowstride,
                   int xdith, int ydith);

  
  void draw_rgb_32_image(
                   const Glib::RefPtr<const GC>& gc,
                   int x, int y, int width, int height,
                   RgbDither dith, const guchar* rgb_buf, int rowstride);

  
  /** Like gdk_draw_rgb_32_image(), but allows you to specify the dither
   * offsets. See gdk_draw_rgb_image_dithalign() for more details.
   * @param gc A Gdk::GC.
   * @param x X coordinate on @a drawable  where image should go.
   * @param y Y coordinate on @a drawable  where image should go.
   * @param width Width of area of image to draw.
   * @param height Height of area of image to draw.
   * @param dith Dithering mode.
   * @param buf RGB image data.
   * @param rowstride Rowstride of RGB image data.
   * @param xdith X dither offset.
   * @param ydith Y dither offset.
   */
  void draw_rgb_32_image_dithalign(
                   const Glib::RefPtr<const GC>& gc,
                   int x, int y, int width, int height,
                   RgbDither dith, const guchar* buf, int rowstride,
                   int xdith, int ydith);

  
  void draw_gray_image(
                   const Glib::RefPtr<const GC>& gc,
                   int x, int y, int width, int height,
                   RgbDither dith, const guchar* rgb_buf, int rowstride);

  
  void draw_indexed_image(
                   const Glib::RefPtr<const GC>& gc,
                   int x, int y, int width, int height,
                   RgbDither dith, const guchar* rgb_buf, int rowstride,
                   const RgbCmap& cmap);

  
  /** Gets the Gdk::Screen associated with a Gdk::Drawable.
   * @return The Gdk::Screen associated with @a drawable 
   * 
   * Since: 2.2.
   */
  Glib::RefPtr<Screen> get_screen();
  
  /** Gets the Gdk::Screen associated with a Gdk::Drawable.
   * @return The Gdk::Screen associated with @a drawable 
   * 
   * Since: 2.2.
   */
  Glib::RefPtr<const Screen> get_screen() const;

  
  /** Gets the Gdk::Display associated with a Gdk::Drawable.
   * @return The Gdk::Display associated with @a drawable 
   * 
   * Since: 2.2.
   */
  Glib::RefPtr<Display> get_display();
  
  /** Gets the Gdk::Display associated with a Gdk::Drawable.
   * @return The Gdk::Display associated with @a drawable 
   * 
   * Since: 2.2.
   */
  Glib::RefPtr<const Display> get_display() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** @relates Gdk::Drawable
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Glib::RefPtr<Gdk::Drawable> wrap(GdkDrawable* object, bool take_copy = false);
}


#endif /* _GDKMM_DRAWABLE_H */

