// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_PANED_H
#define _GTKMM_PANED_H

#include <glibmm.h>

/* $Id$ */


/* paned.h
 * 
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gtkmm/container.h>
#include <gtkmm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkPaned GtkPaned;
typedef struct _GtkPanedClass GtkPanedClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Paned_Class; } // namespace Gtk
#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkHPaned GtkHPaned;
typedef struct _GtkHPanedClass GtkHPanedClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class HPaned_Class; } // namespace Gtk
#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkVPaned GtkVPaned;
typedef struct _GtkVPanedClass GtkVPanedClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class VPaned_Class; } // namespace Gtk
namespace Gtk
{

/** This is the base class for widgets with two panes, arranged either
 * horizontally (Gtk::HPaned) or vertically (Gtk::VPaned).
 *
 * Child widgets are added to the panes of the widget with pack1() and pack2().
 * The division beween the two children is set by default from the size
 * requests of the children, but it can be adjusted by the user.
 *
 * A paned widget draws a separator between the two child widgets and a small
 * handle that the user can drag to adjust the division. It does not draw any
 * relief around the children or around the separator. Often, it is useful to
 * put each child inside a Gtk::Frame with the shadow type set to Gtk::SHADOW_IN
 * so that the gutter appears as a ridge.
 *
 * Each child has two options that can be set - resize and shrink. If resize is
 * true, then when the GtkPaned is resized, that child will expand or shrink
 * along with the paned widget. If shrink is true, then when that child can be
 * made smaller than it's requisition. Setting shrink to false allows the
 * application to set a minimum size. If resize is false for both children,
 * then this is treated as if resize is true for both children.
 *
 * The application can set the position of the slider as if it were set by the
 * user, by calling set_position().
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class Paned : public Container
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Paned CppObjectType;
  typedef Paned_Class CppClassType;
  typedef GtkPaned BaseObjectType;
  typedef GtkPanedClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Paned();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Paned_Class;
  static CppClassType paned_class_;

  // noncopyable
  Paned(const Paned&);
  Paned& operator=(const Paned&);

protected:
  explicit Paned(const Glib::ConstructParams& construct_params);
  explicit Paned(GtkPaned* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkPaned*       gobj()       { return reinterpret_cast<GtkPaned*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkPaned* gobj() const { return reinterpret_cast<GtkPaned*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  Paned();

  
  void add1(Widget& child);
  
  void add2(Widget& child);

  
  void pack1(Widget& child, bool resize, bool shrink);
  void pack1(Widget& child, AttachOptions options = Gtk::EXPAND);

  
  void pack2(Widget& child, bool resize, bool shrink);
  void pack2(Widget& child, AttachOptions options  = Gtk::EXPAND);

  
  /** Obtains the position of the divider between the two panes.
   * @return Position of the divider.
   */
  int get_position() const;
  
  /** Sets the position of the divider between the two panes.
   * @param position Pixel position of divider, a negative value means that the position
   * is unset.
   */
  void set_position(int position);

  
  /** Obtains the first child of the paned widget.
   * @return First child, or <tt>0</tt> if it is not set.
   * 
   * Since: 2.4.
   */
  Widget* get_child1();
  
  /** Obtains the first child of the paned widget.
   * @return First child, or <tt>0</tt> if it is not set.
   * 
   * Since: 2.4.
   */
  const Widget* get_child1() const;

  
  /** Obtains the second child of the paned widget.
   * @return Second child, or <tt>0</tt> if it is not set.
   * 
   * Since: 2.4.
   */
  Widget* get_child2();
  
  /** Obtains the second child of the paned widget.
   * @return Second child, or <tt>0</tt> if it is not set.
   * 
   * Since: 2.4.
   */
  const Widget* get_child2() const;
 
  //Keybinding signals:
  
  
  /** Position of paned separator in pixels (0 means all the way to the left/top).
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_position() ;

/** Position of paned separator in pixels (0 means all the way to the left/top).
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_position() const;

  /** TRUE if the Position property should be used.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_position_set() ;

/** TRUE if the Position property should be used.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_position_set() const;

  /** Smallest possible value for the position property.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_min_position() const;


  /** Largest possible value for the position property.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_max_position() const;


};

/**
 * The Gtk::HPaned widget is a container widget with two children arranged
 * horizontally. The division between the two panes is adjustable by the
 * user by dragging a handle. See Gtk::Paned for details. 
 *
 * @ingroup Widgets
 */

class HPaned : public Paned
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef HPaned CppObjectType;
  typedef HPaned_Class CppClassType;
  typedef GtkHPaned BaseObjectType;
  typedef GtkHPanedClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~HPaned();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class HPaned_Class;
  static CppClassType hpaned_class_;

  // noncopyable
  HPaned(const HPaned&);
  HPaned& operator=(const HPaned&);

protected:
  explicit HPaned(const Glib::ConstructParams& construct_params);
  explicit HPaned(GtkHPaned* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkHPaned*       gobj()       { return reinterpret_cast<GtkHPaned*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkHPaned* gobj() const { return reinterpret_cast<GtkHPaned*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:
  HPaned();


};

/**
 * The Gtk::VPaned widget is a container widget with two children arranged
 * horizontally. The division between the two panes is adjustable by the
 * user by dragging a handle. See Gtk::Paned for details. 
 *
 * @ingroup Widgets
 */

class VPaned : public Paned
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef VPaned CppObjectType;
  typedef VPaned_Class CppClassType;
  typedef GtkVPaned BaseObjectType;
  typedef GtkVPanedClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~VPaned();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class VPaned_Class;
  static CppClassType vpaned_class_;

  // noncopyable
  VPaned(const VPaned&);
  VPaned& operator=(const VPaned&);

protected:
  explicit VPaned(const Glib::ConstructParams& construct_params);
  explicit VPaned(GtkVPaned* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkVPaned*       gobj()       { return reinterpret_cast<GtkVPaned*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkVPaned* gobj() const { return reinterpret_cast<GtkVPaned*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:
  VPaned();


};

} // namespace Gtk


namespace Glib
{
  /** @relates Gtk::Paned
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Gtk::Paned* wrap(GtkPaned* object, bool take_copy = false);
}
namespace Glib
{
  /** @relates Gtk::HPaned
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Gtk::HPaned* wrap(GtkHPaned* object, bool take_copy = false);
}
namespace Glib
{
  /** @relates Gtk::VPaned
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Gtk::VPaned* wrap(GtkVPaned* object, bool take_copy = false);
}
#endif /* _GTKMM_PANED_H */

