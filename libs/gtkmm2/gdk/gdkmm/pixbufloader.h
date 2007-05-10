// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_PIXBUFLOADER_H
#define _GDKMM_PIXBUFLOADER_H

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

#include <glibmm/object.h>
#include <gdkmm/pixbuf.h>
#include <gdkmm/pixbufanimation.h>
#include <gdkmm/pixbufformat.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkPixbufLoader GdkPixbufLoader;
typedef struct _GdkPixbufLoaderClass GdkPixbufLoaderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{ class PixbufLoader_Class; } // namespace Gdk
namespace Gdk
{


class PixbufLoader : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef PixbufLoader CppObjectType;
  typedef PixbufLoader_Class CppClassType;
  typedef GdkPixbufLoader BaseObjectType;
  typedef GdkPixbufLoaderClass BaseClassType;

private:  friend class PixbufLoader_Class;
  static CppClassType pixbufloader_class_;

private:
  // noncopyable
  PixbufLoader(const PixbufLoader&);
  PixbufLoader& operator=(const PixbufLoader&);

protected:
  explicit PixbufLoader(const Glib::ConstructParams& construct_params);
  explicit PixbufLoader(GdkPixbufLoader* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~PixbufLoader();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkPixbufLoader*       gobj()       { return reinterpret_cast<GdkPixbufLoader*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkPixbufLoader* gobj() const { return reinterpret_cast<GdkPixbufLoader*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkPixbufLoader* gobj_copy();

private:

protected:

  /** Constructs a pixbuf loader object.
   */
  PixbufLoader();

  /** Constructs a pixbuf loader object for a specific image type.
   * Constructs a new pixbuf loader object that always attempts to parse image
   * data as if it were an image of type @a image_type, instead of identifying
   * the type automatically. Useful if you want an error if the image isn't the
   * expected type, for loading image formats that can't be reliably identified
   * by looking at the data, or if the user manually forces a specific type.
   *
   * The image_type can be one of the types returned by Gdk::Pixbuf::get_formats(), or a MIME type.
   *
   * Common MIME Types are listed here
   * http://www.iana.org/assignments/media-types/
   * and here:
   * http://www.freedesktop.org/Software/shared-mime-info
   *
   * @param image_type Name of the image format to be loaded with the image.
   * @param mime_type If this is true then the image_type is a MIME type.
   * @throw Gdk::PixbufError
   */
  explicit PixbufLoader(const Glib::ustring& image_type, bool mime_type = false);
  //TODO: What non-mime-types names are possible?

public:

  /** Creates a new pixbuf loader object.
   * @return A newly-created pixbuf loader.
   */
  
  static Glib::RefPtr<PixbufLoader> create();


   /** Constructs a pixbuf loader object for a specific image type.
   * Constructs a new pixbuf loader object that always attempts to parse image
   * data as if it were an image of type @a image_type, instead of identifying
   * the type automatically. Useful if you want an error if the image isn't the
   * expected type, for loading image formats that can't be reliably identified
   * by looking at the data, or if the user manually forces a specific type.
   *
   * The image_type can be one of the types returned by Gdk::Pixbuf::get_formats(), or a MIME type.
   *
   * Common MIME Types are listed here
   * http://www.iana.org/assignments/media-types/
   * and here:
   * http://www.freedesktop.org/Software/shared-mime-info
   *
   * @param image_type Name of the image format to be loaded with the image.
   * @param mime_type If this is true then the image_type is a MIME type.
   * @throw Gdk::PixbufError
   */
  
  static Glib::RefPtr<PixbufLoader> create(const Glib::ustring& image_type, bool mime_type =  false);


  /** Causes the image to be scaled while it is loaded. The desired
   * image size can be determined relative to the original size of
   * the image by calling set_size() from a
   * signal handler for the ::size_prepared signal.
   * 
   * Attempts to set the desired image size  are ignored after the 
   * emission of the ::size_prepared signal.
   * 
   * Since: 2.2
   * @param width The desired width of the image being loaded.
   * @param height The desired height of the image being loaded.
   */
  void set_size(int width, int height);
          
  /** Causes the pixbuf loader to parse the next @a count bytes of an image.
   * It will return if the data was loaded successfully, and throw an exception
   * if an error occurred. In the latter case, the loader will be closed, and
   * will not accept further writes.
   * @param buf Pointer to image data.
   * @param count Length of the @a buf buffer in bytes.
   * @throw Gdk::PixbufError
   * @throw Glib::FileError
   */
  void write(const guint8* buf, gsize count);
  

  /** Informs a pixbuf loader that no further writes with PixbufLoader::write()
   * will occur, so that it can free its internal loading structures.  Also,
   * tries to parse any data that hasn't yet been parsed; if the remaining data
   * is partial or corrupt, an exception will be thrown. If you're just
   * cancelling a load rather than expecting it to be finished, writing an
   * empty <tt>catch()</tt> block to ignore errors is reasonable.
   * @throw Gdk::PixbufError
   * @throw Glib::FileError
   */
  void close();
  

  /** Queries the Gdk::Pixbuf that a pixbuf loader is currently creating.
   * In general it only makes sense to call this function after the
   * "area_prepared" signal has been emitted by the loader; this means
   * that enough data has been read to know the size of the image that
   * will be allocated.  If the loader has not received enough data via
   * write(), then this function returns <tt>0</tt>.  The
   * returned pixbuf will be the same in all future calls to the loader,
   * so simply calling Glib::object_ref() should be sufficient to continue
   * using it.  Additionally, if the loader is an animation, it will
   * return the "static image" of the animation
   * (see Gdk::PixbufAnimation::get_static_image()).
   * @return The Gdk::Pixbuf that the loader is creating, or <tt>0</tt> if not
   * enough data has been read to determine how to create the image buffer.
   */
  Glib::RefPtr<Gdk::Pixbuf> get_pixbuf();
  
  /** Queries the Gdk::PixbufAnimation that a pixbuf loader is currently creating.
   * In general it only makes sense to call this function after the "area_prepared"
   * signal has been emitted by the loader. If the loader doesn't have enough
   * bytes yet (hasn't emitted the "area_prepared" signal) this function will 
   * return <tt>0</tt>.
   * @return The Gdk::PixbufAnimation that the loader is loading, or <tt>0</tt> if
   *  not enough data has been read to determine the information.
   */
  Glib::RefPtr<Gdk::PixbufAnimation> get_animation();

  
  /** Obtains the available information about the format of the 
   * currently loading image file.
   * @return A Gdk::PixbufFormat or <tt>0</tt>. The return value is owned 
   * by GdkPixbuf and should not be freed.
   * 
   * Since: 2.2.
   */
  PixbufFormat get_format() const;

  
  Glib::SignalProxy0< void > signal_area_prepared();

  
  Glib::SignalProxy4< void,int,int,int,int > signal_area_updated();

  
  Glib::SignalProxy0< void > signal_closed();

  
  //We use no_default_handler for this, because we can not add a new vfunc to 2.5 without breaking ABI.
  //TODO: Remove no_default_handler when we do an ABI-break-with-parallel-install.
  

  Glib::SignalProxy2< void,int,int > signal_size_prepared();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_area_prepared();
  virtual void on_area_updated(int x, int y, int width, int height);
  virtual void on_closed();


};

} // namespace Gdk


namespace Glib
{
  /** @relates Gdk::PixbufLoader
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Glib::RefPtr<Gdk::PixbufLoader> wrap(GdkPixbufLoader* object, bool take_copy = false);
}


#endif /* _GDKMM_PIXBUFLOADER_H */

