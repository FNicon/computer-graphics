/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#pragma once

#include <bits/stdc++.h>

using namespace std;


// Point.

class Point {
public:
  /** X-axis. */
  int x = 0;
  /** Y-axis. */
  int y = 0;

  /**
   * Set object from input stream.
   *
   * @param _is  input stream to be read.
   * @param _obj  object to be set.
   */
  friend istream& operator>> (istream& _is, Point& _obj);

  /**
   * Print object to output stream.
   *
   * @param _os  output stream to be written.
   * @param _obj  object to be read.
   */
  friend ostream& operator<< (ostream& _os, const Point& _obj);
};
