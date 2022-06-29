#include <stdio.h>
#include "shape.h"

Shape* create_shape(shape_type type)
{
  switch (type) {
  case shape_type::Circle:
    return new Circle();
  case shape_type::Triangle:
    return new Triangle();
  case shape_type::Rectangle:
    return new Rectangle();
  default:
      break;;
  }
  return new Shape();
}

void foo()
{
    ShapeWrapper ptr_wrapper(
        create_shape(shape_type::Circle));
}