// Generated by gtkmmproc -- DO NOT MODIFY!

#include <gtkmm/scrollbar.h>
#include <gtkmm/private/scrollbar_p.h>

// -*- c++ -*-
/* $Id$ */

/* 
 *
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <gtkmm/adjustment.h>

#include <gtk/gtkscrollbar.h>
#include <gtk/gtkhscrollbar.h>
#include <gtk/gtkvscrollbar.h>

namespace Gtk
{

VScrollbar::VScrollbar(Adjustment& adjustment)
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Scrollbar(Glib::ConstructParams(vscrollbar_class_.init(), (char*) 0))
{
  set_adjustment(adjustment);
}

VScrollbar::VScrollbar()
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Scrollbar(Glib::ConstructParams(vscrollbar_class_.init(), (char*) 0))
{
  Adjustment* adjustment = manage(new Adjustment(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  // The adjustment will be destroyed along with the object
  set_adjustment(*adjustment);
}


HScrollbar::HScrollbar()
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Scrollbar(Glib::ConstructParams(hscrollbar_class_.init(), (char*) 0))
{
  Adjustment* adjustment = manage(new Adjustment(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  // The adjustment will be destroyed along with the object
  set_adjustment(*adjustment);
}

HScrollbar::HScrollbar(Adjustment& adjustment)
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Scrollbar(Glib::ConstructParams(hscrollbar_class_.init(), (char*) 0))
{
  set_adjustment(adjustment);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Scrollbar* wrap(GtkScrollbar* object, bool take_copy)
{
  return dynamic_cast<Gtk::Scrollbar *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Scrollbar_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Scrollbar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_scrollbar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void Scrollbar_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

}


Glib::ObjectBase* Scrollbar_Class::wrap_new(GObject* o)
{
  return manage(new Scrollbar((GtkScrollbar*)(o)));

}


/* The implementation: */

Scrollbar::Scrollbar(const Glib::ConstructParams& construct_params)
:
  Gtk::Range(construct_params)
{
  }

Scrollbar::Scrollbar(GtkScrollbar* castitem)
:
  Gtk::Range((GtkRange*)(castitem))
{
  }

Scrollbar::~Scrollbar()
{
  destroy_();
}

Scrollbar::CppClassType Scrollbar::scrollbar_class_; // initialize static member

GType Scrollbar::get_type()
{
  return scrollbar_class_.init().get_type();
}

GType Scrollbar::get_base_type()
{
  return gtk_scrollbar_get_type();
}


} // namespace Gtk


namespace Glib
{

Gtk::VScrollbar* wrap(GtkVScrollbar* object, bool take_copy)
{
  return dynamic_cast<Gtk::VScrollbar *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& VScrollbar_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &VScrollbar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_vscrollbar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void VScrollbar_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

}


Glib::ObjectBase* VScrollbar_Class::wrap_new(GObject* o)
{
  return manage(new VScrollbar((GtkVScrollbar*)(o)));

}


/* The implementation: */

VScrollbar::VScrollbar(const Glib::ConstructParams& construct_params)
:
  Gtk::Scrollbar(construct_params)
{
  }

VScrollbar::VScrollbar(GtkVScrollbar* castitem)
:
  Gtk::Scrollbar((GtkScrollbar*)(castitem))
{
  }

VScrollbar::~VScrollbar()
{
  destroy_();
}

VScrollbar::CppClassType VScrollbar::vscrollbar_class_; // initialize static member

GType VScrollbar::get_type()
{
  return vscrollbar_class_.init().get_type();
}

GType VScrollbar::get_base_type()
{
  return gtk_vscrollbar_get_type();
}


} // namespace Gtk


namespace Glib
{

Gtk::HScrollbar* wrap(GtkHScrollbar* object, bool take_copy)
{
  return dynamic_cast<Gtk::HScrollbar *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& HScrollbar_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &HScrollbar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_hscrollbar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void HScrollbar_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

}


Glib::ObjectBase* HScrollbar_Class::wrap_new(GObject* o)
{
  return manage(new HScrollbar((GtkHScrollbar*)(o)));

}


/* The implementation: */

HScrollbar::HScrollbar(const Glib::ConstructParams& construct_params)
:
  Gtk::Scrollbar(construct_params)
{
  }

HScrollbar::HScrollbar(GtkHScrollbar* castitem)
:
  Gtk::Scrollbar((GtkScrollbar*)(castitem))
{
  }

HScrollbar::~HScrollbar()
{
  destroy_();
}

HScrollbar::CppClassType HScrollbar::hscrollbar_class_; // initialize static member

GType HScrollbar::get_type()
{
  return hscrollbar_class_.init().get_type();
}

GType HScrollbar::get_base_type()
{
  return gtk_hscrollbar_get_type();
}


} // namespace Gtk


