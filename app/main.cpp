// Copyright 2017 AKonia
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <cmath>
#include <cstdint>
#include <list>
#include <utility>
#include "graph.h"
#include "kruskal.h"

#define WIDTH 800
#define MAX_VERTEX_COUNT 60
#define CIRCLE_RADIUS 20

#define WINDOW_NAME "MST Visualis"
#define TRACKBAR_NAME "Weight"

using std::list;
using std::pair;
using std::make_pair;
using cv::Point;
using cv::line;
using cv::circle;
using cv::Mat;
using cv::putText;
using cv::Scalar;
using cv::waitKey;
using cv::namedWindow;
using cv::WINDOW_AUTOSIZE;
using cv::Size;
using cv::getTextSize;

struct Edge {
  uint32_t e_weight;
  uint32_t v_from;
  uint32_t v_to;
  Point coord_from;
  Point coord_to;
};

Edge make_edge(uint32_t e_weight, uint32_t v_from, uint32_t v_to,
               Point coord_from, Point coord_to) {
  return {e_weight, v_from, v_to, coord_from, coord_to};
}

int currentMaxVert = 0;
int coords[2];
char TestStr[100];
int slider;
int verticesCount;

Mat canvas;

list<pair<int, Point> > vertices;
list<Edge> edges;

Graph *g;
list<pair<uint32_t, uint32_t> > points;

void redrawMem(int mode = 0) {
  canvas = Mat::zeros(WIDTH, WIDTH, CV_8UC3);
  if (mode > 0) {
    if (g != nullptr) delete g;
    g = new Graph(vertices.size());
    for (list<Edge>::iterator e = edges.begin(); e != edges.end(); ++e)
      g->setEdge(e->v_from, e->v_to, e->e_weight);
    points = findMinSpanTreeKruskal(*g);
  }
  bool flagToHighlight = false;
  for (list<Edge>::iterator e = edges.begin(); e != edges.end(); ++e) {
    int x[2], y[2];
    x[0] = e->coord_from.x;
    y[0] = e->coord_from.y;
    x[1] = e->coord_to.x;
    y[1] = e->coord_to.y;

    flagToHighlight = false;
    for (list<pair<uint32_t, uint32_t> >::iterator i = points.begin();
         i != points.end(); ++i) {
      if (((e->v_from == i->first) && (e->v_to == i->second)) ||
          ((e->v_to == i->first) && (e->v_from == i->second))) {
        flagToHighlight = true;
        break;
      }
    }

    int line_len_x = x[1] - x[0], line_len_y = y[1] - y[0];
    int linelen = sqrt(line_len_x * line_len_x + line_len_y * line_len_y);
    line(canvas, Point(x[0] + 2 * CIRCLE_RADIUS * line_len_x / (1 + linelen),
                       y[0] + 2 * CIRCLE_RADIUS * line_len_y / (1 + linelen)),
         Point(x[1] - 2 * CIRCLE_RADIUS * line_len_x / (1 + linelen),
               y[1] - 2 * CIRCLE_RADIUS * line_len_y / (1 + linelen)),
         ((mode == 0) || (flagToHighlight)) ? Scalar(0, 255, 0)
                                            : Scalar(64, 64, 64),
         2, 1);
    snprintf(TestStr, sizeof(TestStr), "%d", e->e_weight);
    putText(canvas, TestStr,
            Point((x[0] + x[1]) / 2 + (20 * line_len_y / (1 + linelen)),
                  (y[0] + y[1]) / 2 - (20 * line_len_x / (1 + linelen))),
            CV_FONT_NORMAL, 1, Scalar(255, 255, 255), 1, 1);
  }

  for (list<pair<int, Point> >::iterator i = vertices.begin();
       i != vertices.end(); ++i) {
    snprintf(TestStr, sizeof(TestStr), "%d", i->first);
    Size textSize = getTextSize(TestStr, 1, 1, 1, NULL);
    putText(canvas, TestStr, Point(i->second.x - textSize.width,
                                   i->second.y + textSize.height / 2 + 5),
            CV_FONT_NORMAL, 1, Scalar(255, 255, 255), 1, 1);
    circle(canvas, Point(i->second.x, i->second.y), 30, Scalar(255, 128, 128),
           1, CIRCLE_RADIUS, 0);
  }
  imshow(WINDOW_NAME, canvas);
}

static void onMouse(int event, int x, int y, int a, void *vvvvv) {
  static bool flag1 = false;
  static bool flag2 = false;
  static bool vertexStarted = false;
  static bool edgeStarted = false;
  if (edgeStarted) {
    if (flag2) {
      redrawMem();
      int cords[2];
      cords[0] = coords[0];
      cords[1] = coords[1];
      int line_len_x = x - cords[0], line_len_y = y - cords[1];
      int linelen = hypot(line_len_x, line_len_y);
      line(canvas,
           Point(cords[0] + 2 * CIRCLE_RADIUS * line_len_x / (1 + linelen),
                 cords[1] + 2 * CIRCLE_RADIUS * line_len_y / (1 + linelen)),
           Point(x, y), Scalar(0, 255, 0), 2, 1);
      snprintf(TestStr, sizeof(TestStr), "%d", slider);
      putText(canvas, TestStr,
              Point((cords[0] + x) / 2 + ((0 * line_len_y) / (1 + linelen)),
                    (cords[1] + y) / 2 - ((0 * line_len_x) / (1 + linelen))),
              CV_FONT_NORMAL, 1, Scalar(255, 255, 255), 1, 1);
      imshow(WINDOW_NAME, canvas);
    }
}
  if (vertexStarted) {
    if (flag1) {
      redrawMem();
      snprintf(TestStr, sizeof(TestStr), "%d",
static_cast<int>(vertices.size()));
      Size textSize = getTextSize(TestStr, 1, 1, 1, NULL);
      putText(canvas, TestStr,
              Point(x - textSize.width, y + textSize.height / 2 + 5),
              CV_FONT_NORMAL, 1, Scalar(255, 255, 255), 1, 1);
      circle(canvas, Point(x, y), 30, Scalar(255, 128, 128), 1, CIRCLE_RADIUS,
             0);
      imshow(WINDOW_NAME, canvas);
    }
}
  static int v_to = 0;
  static int v_from = 0;
  switch (event) {
    case CV_EVENT_LBUTTONDOWN: {
      if (vertices.size() >= MAX_VERTEX_COUNT) break;
      edgeStarted = false;
      vertexStarted = true;
      coords[0] = x;
      coords[1] = y;
      flag1 = true;
      imshow(WINDOW_NAME, canvas);
      break;
    }
    case CV_EVENT_LBUTTONUP: {
      if (vertices.size() >= MAX_VERTEX_COUNT) break;
      flag1 = false;
      if (!vertexStarted) break;
      vertices.push_back(make_pair(vertices.size(), Point(x, y)));
      redrawMem();
      vertexStarted = false;
      break;
    }
    case CV_EVENT_RBUTTONDOWN: {
      if (slider == 0) break;
      vertexStarted = false;
      for (list<pair<int, Point> >::iterator i = vertices.begin();
           i != vertices.end(); ++i) {
        if (hypot(x - i->second.x, y - i->second.y) <= 2 * CIRCLE_RADIUS) {
          v_from = i->first;
          coords[0] = i->second.x;
          coords[1] = i->second.y;
          edgeStarted = true;
          flag2 = true;
        }
      }
      break;
    }
    case CV_EVENT_RBUTTONUP: {
      if (slider == 0) break;
      snprintf(TestStr, sizeof(TestStr), "%d", slider);
      for (list<pair<int, Point> >::iterator i = vertices.begin();
           i != vertices.end(); ++i) {
        if (hypot(x - i->second.x, y - i->second.y) <= 2 * CIRCLE_RADIUS) {
          v_to = i->first;
          x = i->second.x;
          y = i->second.y;
          flag2 = false;
        }
      }
      if (edgeStarted && !flag2 && !((coords[0] == x) && (coords[1] == y)))
        edges.push_back(make_edge(slider, v_from, v_to,
                                  Point(coords[0], coords[1]), Point(x, y)));
      else
        flag2 = false;
      edgeStarted = false;
      redrawMem();
      break;
    }
    case CV_EVENT_LBUTTONDBLCLK: {
      vertices.clear();
      edges.clear();
      points.clear();
      redrawMem();
    }
    case CV_EVENT_MBUTTONDOWN:
      redrawMem(1);
      break;
  }
}

static void onTrackBar(int value) { slider = value; }

int main() {
  verticesCount = 0;
  CvFont *font = new CvFont;
  cvInitFont(font, CV_FONT_VECTOR0, 0.5f, 0.8f, 0, 1, 8);
  slider = 0;
  canvas = Mat::zeros(WIDTH, WIDTH, CV_8UC3);
  snprintf(TestStr, sizeof(TestStr), "Hapucyu");
  putText(canvas, TestStr,
          Point(400 - getTextSize(TestStr, 1, 1, 1, NULL).width, 400),
          CV_FONT_NORMAL, 1, Scalar(255, 255, 255), 1, 1);
  circle(canvas, Point(400, 400), 200, Scalar(255, 0, 255), 1, 8, 0);
  namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
  cvCreateTrackbar(TRACKBAR_NAME, WINDOW_NAME, &slider, 150, onTrackBar);
  cvSetMouseCallback(WINDOW_NAME, onMouse, NULL);
  imshow(WINDOW_NAME, canvas);
  waitKey(0);
  return 0;
}
