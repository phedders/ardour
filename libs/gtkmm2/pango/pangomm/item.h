// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _PANGOMM_ITEM_H
#define _PANGOMM_ITEM_H

#include <glibmm.h>

/* Copyright (C) 2002 The gtkmm Development Team
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
 
#include <pangomm/attributes.h>
#include <pangomm/language.h>
#include <pango/pango-item.h>


namespace Pango
{

class Font;
class GlyphString;

/** A Pango::Analysis stores information about the properties of a segment of text.
 * Pango::Analysis is used as an output type only so there is no public default constructor.
 * You can retrieve an object of this type from an object of type Pango::Item by
 * calling Pango::Item::get_analysis(). Objects of this class can be used for some
 * calculations in Pango::GlyphString.
 */
class Analysis
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Analysis CppObjectType;
  typedef PangoAnalysis BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  // This class is only used as an output type.
  Analysis();

public:
  explicit Analysis(const PangoAnalysis* src);

public:
//  _MEMBER_GET_PTR(engine_shape, shape_engine, EngineShape*, PangoEngineShape*) //We don't wrap the Engine* stuff.
//  _MEMBER_GET_PTR(engine_lang, lang_engine, EngineLang*, PangoEngineLang*)

  /** Gets the font used to render this segment.
   * @return The font used to render this segment.
   */
  Glib::RefPtr<Font> get_font();
  Glib::RefPtr<const Font> get_font() const;

  /** Gets the bidrectional level for this segment.
   * @return The bidirectional level for this segment.
   */
  guint8 get_level() const;

  /** Gets the language of this segment.
   * @return The language of this segment.
   */
  Language get_language() const;

  /** Gets a list of non-font attributes for this segment.
   * @return A list of non-font attributes for this segment.
   */
  SListHandle_Attribute get_extra_attrs() const;

  /// Provides access to the underlying C GObject.
  PangoAnalysis*       gobj()       { return &gobject_; }
  /// Provides access to the underlying C GObject.
  const PangoAnalysis* gobj() const { return &gobject_; }

protected:
  PangoAnalysis gobject_;


};


/** A Pango::Item stores information about a segment of text.
 * Pango::Item is used as an output type only so there is no public default constructor.
 * You retrieve objects of this type by calling Pango::Context::itemize() with some text.
 * The actual rendering of the segment of text that corresponds to a particular Pango::Item
 * (or some sub-string) into a string of glyphs is done with shape().
 * The segment of text that corresponds to a Pango::Item can be computed from the
 * text passed into Pango::Context::itemize() with get_segment(). Together with
 * the Pango::Analysis data member that can be accessed with get_analysis()
 * it is needed for further calculations in Pango::GlyphString.
 */
class Item
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Item CppObjectType;
  typedef PangoItem BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:
 //There is the whole set of functions for _CLASS_BOXEDTYPE but unfortunately PangoItem is not registered as a boxed type and lacks pango_item_get_type...
  

public:
  // There is no default constructor. This class is only used as an output type.
  explicit Item(PangoItem* castitem, bool make_a_copy = true);

  Item(const Item& src);
  Item& operator=(const Item& src);

  ~Item();

  /// Provides access to the underlying C GObject. The caller is responsible for freeing it. Use when directly setting fields in structs.
  PangoItem* gobj_copy() const;

public:
  
  /** Modifies @a orig  to cover only the text after @a split_index , and
   * returns a new item that covers the text before @a split_index  that
   * used to be in @a orig . You can think of @a split_index  as the length of
   * the returned item. @a split_index  may not be 0, and it may not be
   * greater than or equal to the length of @a orig  (that is, there must
   * be at least one byte assigned to each item, you can't create a
   * zero-length item). @a split_offset  is the length of the first item in
   * chars, and must be provided because the text used to generate the
   * item isn't available, so pango_item_split() can't count the char
   * length of the split items itself.
   * @param split_index Byte index of position to split item, relative to the start of the item.
   * @param split_offset Number of chars between start of @a orig  and @a split_index .
   * @return New item representing text before @a split_index .
   */
  Item split(int split_index, int split_offset);

  /** Gets the offset of the segment from the beginning of the string in bytes.
   * @return The offset of the segment from the beginning of the string in bytes.
   */
  int get_offset() const;

  /** Gets the length of the segment in bytes.
   * @return The length of the segment in bytes.
   */
  int get_length() const;

  /** Gets the length of the segment in characters.
   * @return The length of the semgment in characters.
   */
  int get_num_chars() const;

  /** Gets the properties of the segment.
   * @return The properties of the segment.
   */
  Analysis get_analysis() const;

  /** Computes the segment of text that is represented by the item.
   * @param text The text that has been passed into Pango::Context::itemize().
   * @return The sub-string of @a text that corresponds to the item.
   */
  Glib::ustring get_segment(const Glib::ustring& text) const;

  /** Convert a segment of text into a string of glyphs.
   * @param text The text to process. This must either be the whole segment of text that corresponds to the item as returned by get_segment() or a sub-string of that segment. You need to pass the same text to the member functions of Pango::GlyphString for further calculations.
   * @return A Pango::GlyphString object that can be measured or drawn.
   */
  GlyphString shape(const Glib::ustring& text) const;

  /// Provides access to the underlying C GObject.  
  PangoItem*       gobj()       { return gobject_; }
  /// Provides access to the underlying C GObject.
  const PangoItem* gobj() const { return gobject_; }

protected:
  PangoItem* gobject_;


};

struct ItemTraits
{
  typedef Pango::Item       CppType;
  typedef const PangoItem*  CType;
  typedef PangoItem*        CTypeNonConst;

  static CType   to_c_type      (const CppType& obj) { return obj.gobj(); }
  static CType   to_c_type      (CType ptr) { return ptr; }
  static CppType to_cpp_type    (CType ptr) { return CppType(const_cast<CTypeNonConst>(ptr), true); }
  static void    release_c_type (CType ptr) { pango_item_free(const_cast<CTypeNonConst>(ptr)); }
};

typedef Glib::ListHandle<Item, ItemTraits> ListHandle_Item;

} // namespace Pango


namespace Glib
{

/** @relates Pango::Analysis */
Pango::Analysis& wrap(PangoAnalysis* object);

/** @relates Pango::Analysis */
const Pango::Analysis& wrap(const PangoAnalysis* object);

/** @relates Pango::Item */
Pango::Item wrap(PangoItem* object, bool take_copy=true);

} // namespace Glib


#endif /* _PANGOMM_ITEM_H */

