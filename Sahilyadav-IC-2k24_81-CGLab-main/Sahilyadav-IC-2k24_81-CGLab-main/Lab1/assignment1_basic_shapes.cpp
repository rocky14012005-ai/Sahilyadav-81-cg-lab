/*
 * ======================================================================================
 * CGM LAB ASSIGNMENT - 1
 * --------------------------------------------------------------------------------------
 * Title       : Basic Graphics Primitives (Line, Circle, Rectangle, Triangle)
 * Student Name: Srishtee Dayma
 * Roll No     : 104
 * Batch       : IC-2k24
 * Course      : Computer Graphics & Multimedia Lab (CGM Lab)
 * Description : A C++ graphics program using WinBGIm (graphics.h) to draw four basic
 *               graphics primitives (Line, Circle, Rectangle, Triangle) in a single
 *               window with labeled sections, coordinates, and styling.
 * ======================================================================================
 */

#include <graphics.h>
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    // Check if running in non-interactive / screenshot capture mode
    bool autoExit = false;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--save-and-exit") == 0) {
            autoExit = true;
        }
    }

    // Initialize 800x600 Graphics Window
    const int screenWidth = 800;
    const int screenHeight = 600;
    initwindow(screenWidth, screenHeight, "CGM Lab Assignment 1 - Basic Shapes | Srishtee Dayma (Roll: 104)");

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // -------------------------------------------------------------------------
    // 1. OUTER BORDER & STRUCTURE
    // -------------------------------------------------------------------------
    setcolor(DARKGRAY);
    rectangle(10, 10, screenWidth - 10, screenHeight - 10);
    rectangle(12, 12, screenWidth - 12, screenHeight - 12);

    // -------------------------------------------------------------------------
    // 2. HEADER BANNER
    // -------------------------------------------------------------------------
    setcolor(LIGHTBLUE);
    rectangle(18, 18, screenWidth - 18, 85);

    // Title text
    settextjustify(CENTER_TEXT, TOP_TEXT);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(screenWidth / 2, 28, const_cast<char*>("CGM LAB ASSIGNMENT 1: BASIC SHAPES"));

    // Subtitle text (Student Details)
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTCYAN);
    outtextxy(screenWidth / 2, 58, const_cast<char*>("Student: Srishtee Dayma  |  Roll No: 104  |  Batch: IC-2k24"));

    // -------------------------------------------------------------------------
    // 3. QUADRANT DIVIDERS
    // -------------------------------------------------------------------------
    setcolor(DARKGRAY);
    // Horizontal divider
    line(18, 325, screenWidth - 18, 325);
    // Vertical divider
    line(screenWidth / 2, 85, screenWidth / 2, 545);
    // Footer top line
    line(18, 545, screenWidth - 18, 545);

    // =========================================================================
    // QUADRANT 1: STRAIGHT LINE (Top-Left)
    // =========================================================================
    // Section Header
    settextjustify(CENTER_TEXT, TOP_TEXT);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(CYAN);
    outtextxy(200, 100, const_cast<char*>("1. STRAIGHT LINE"));

    setcolor(WHITE);
    outtextxy(200, 118, const_cast<char*>("Function: line(x1, y1, x2, y2)"));

    // Coordinates: (70, 250) to (330, 170)
    int lineX1 = 70,  lineY1 = 250;
    int lineX2 = 330, lineY2 = 170;

    // Draw straight line
    setcolor(LIGHTCYAN);
    line(lineX1, lineY1, lineX2, lineY2);

    // Endpoint markers
    setcolor(YELLOW);
    circle(lineX1, lineY1, 4);
    circle(lineX2, lineY2, 4);

    // Endpoint coordinate labels
    setcolor(LIGHTGRAY);
    settextjustify(CENTER_TEXT, TOP_TEXT);
    outtextxy(lineX1, lineY1 + 10, const_cast<char*>("P1 (70, 250)"));
    outtextxy(lineX2, lineY2 - 20, const_cast<char*>("P2 (330, 170)"));

    // =========================================================================
    // QUADRANT 2: CIRCLE (Top-Right)
    // =========================================================================
    // Section Header
    settextjustify(CENTER_TEXT, TOP_TEXT);
    setcolor(YELLOW);
    outtextxy(600, 100, const_cast<char*>("2. CIRCLE"));

    setcolor(WHITE);
    outtextxy(600, 118, const_cast<char*>("Function: circle(xc, yc, radius)"));

    // Circle specs: Center (600, 215), Radius 65
    int circleXc = 600, circleYc = 215, circleRadius = 65;

    // Draw circle
    setcolor(YELLOW);
    circle(circleXc, circleYc, circleRadius);

    // Center point marker & radius line
    setcolor(LIGHTRED);
    circle(circleXc, circleYc, 3);
    line(circleXc, circleYc, circleXc + circleRadius, circleYc);

    // Labels
    setcolor(LIGHTGRAY);
    outtextxy(circleXc, circleYc + 8, const_cast<char*>("Center (600, 215)"));
    outtextxy(circleXc + 35, circleYc - 16, const_cast<char*>("r = 65"));

    // =========================================================================
    // QUADRANT 3: RECTANGLE (Bottom-Left)
    // =========================================================================
    // Section Header
    settextjustify(CENTER_TEXT, TOP_TEXT);
    setcolor(LIGHTGREEN);
    outtextxy(200, 340, const_cast<char*>("3. RECTANGLE"));

    setcolor(WHITE);
    outtextxy(200, 358, const_cast<char*>("Function: rectangle(left, top, right, bottom)"));

    // Rectangle coords
    int rectLeft = 80, rectTop = 385, rectRight = 320, rectBottom = 495;

    // Draw rectangle
    setcolor(LIGHTGREEN);
    rectangle(rectLeft, rectTop, rectRight, rectBottom);

    // Corner labels
    setcolor(LIGHTGRAY);
    outtextxy(rectLeft + 45, rectTop - 16, const_cast<char*>("(80, 385)"));
    outtextxy(rectRight - 45, rectBottom + 6, const_cast<char*>("(320, 495)"));

    // Dimension annotation
    setcolor(WHITE);
    outtextxy(200, 435, const_cast<char*>("Width: 240 px  |  Height: 110 px"));

    // =========================================================================
    // QUADRANT 4: TRIANGLE (Bottom-Right)
    // =========================================================================
    // Section Header
    settextjustify(CENTER_TEXT, TOP_TEXT);
    setcolor(LIGHTMAGENTA);
    outtextxy(600, 340, const_cast<char*>("4. TRIANGLE"));

    setcolor(WHITE);
    outtextxy(600, 358, const_cast<char*>("Constructed via 3 Connected Lines"));

    // Triangle vertices: V1(Top), V2(Bottom-Left), V3(Bottom-Right)
    int triX1 = 600, triY1 = 385; // Top
    int triX2 = 490, triY2 = 495; // Bottom-Left
    int triX3 = 710, triY3 = 495; // Bottom-Right

    // Draw 3 sides of triangle
    setcolor(LIGHTMAGENTA);
    line(triX1, triY1, triX2, triY2);
    line(triX2, triY2, triX3, triY3);
    line(triX3, triY3, triX1, triY1);

    // Vertex point markers
    setcolor(YELLOW);
    circle(triX1, triY1, 3);
    circle(triX2, triY2, 3);
    circle(triX3, triY3, 3);

    // Vertex coordinate labels
    setcolor(LIGHTGRAY);
    outtextxy(triX1, triY1 - 18, const_cast<char*>("V1 (600, 385)"));
    outtextxy(triX2, triY2 + 8,  const_cast<char*>("V2 (490, 495)"));
    outtextxy(triX3, triY3 + 8,  const_cast<char*>("V3 (710, 495)"));

    // -------------------------------------------------------------------------
    // 5. FOOTER STATUS BAR
    // -------------------------------------------------------------------------
    settextjustify(CENTER_TEXT, TOP_TEXT);
    setcolor(LIGHTGRAY);
    outtextxy(screenWidth / 2, 560, const_cast<char*>("CGM Lab 1 Output generated successfully. Press any key to exit."));

    // Save screenshot of the output window
    writeimagefile("output.png", 0, 0, screenWidth, screenHeight);

    // Wait for user input unless running in automated mode
    if (!autoExit) {
        getch();
    }

    closegraph();
    return 0;
}
