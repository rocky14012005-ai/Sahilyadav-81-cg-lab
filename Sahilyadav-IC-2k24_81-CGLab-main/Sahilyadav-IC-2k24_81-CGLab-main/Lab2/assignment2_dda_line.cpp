/*
 * ======================================================================================
 * CGM LAB ASSIGNMENT - 2
 * --------------------------------------------------------------------------------------
 * Title       : DDA (Digital Differential Analyzer) Line Drawing Algorithm
 * Student Name: Srishtee Dayma
 * Roll No     : 104
 * Batch       : IC-2k24
 * Course      : Computer Graphics & Multimedia Lab (CGM Lab)
 * Description : Implementation of the DDA Line Drawing Algorithm in C++ using WinBGIm
 *               (graphics.h). Calculates steps, increments (xInc, yInc), and plots lines
 *               pixel-by-pixel for various slope conditions with mathematical table
 *               visualization and pixel grid demonstration.
 * ======================================================================================
 */

#include <graphics.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

// Structure to hold information and mathematical parameters for a DDA line
struct DDAStats {
    std::string name;
    int x1, y1, x2, y2;
    float dx, dy;
    int steps;
    float xInc, yInc;
    float slope;
    int color;
};

// Custom DDA Line Drawing Algorithm function
DDAStats drawDDALine(const std::string& name, int x1, int y1, int x2, int y2, int color) {
    DDAStats stats;
    stats.name = name;
    stats.x1 = x1; stats.y1 = y1;
    stats.x2 = x2; stats.y2 = y2;
    stats.color = color;

    float dx = static_cast<float>(x2 - x1);
    float dy = static_cast<float>(y2 - y1);
    stats.dx = dx;
    stats.dy = dy;

    // Calculate required steps based on maximum change in x or y
    int steps = static_cast<int>(std::max(std::abs(dx), std::abs(dy)));
    stats.steps = steps;

    // Calculate coordinate increment per step
    float xInc = (steps == 0) ? 0.0f : dx / static_cast<float>(steps);
    float yInc = (steps == 0) ? 0.0f : dy / static_cast<float>(steps);
    stats.xInc = xInc;
    stats.yInc = yInc;

    // Calculate slope m = dy / dx
    stats.slope = (dx == 0.0f) ? 999.0f : (dy / dx);

    // Initial floating-point coordinates
    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    // Plot line pixel-by-pixel
    for (int i = 0; i <= steps; ++i) {
        putpixel(static_cast<int>(round(x)), static_cast<int>(round(y)), color);
        x += xInc;
        y += yInc;
    }

    return stats;
}

// Function to draw thick endpoint markers
void drawEndpointMarker(int x, int y, int color) {
    setcolor(color);
    circle(x, y, 3);
    circle(x, y, 4);
}

int main(int argc, char* argv[]) {
    // Check command line arguments for automated mode
    bool autoExit = false;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--save-and-exit") == 0) {
            autoExit = true;
        }
    }

    // Initialize 900x650 Graphics Window
    const int screenWidth = 900;
    const int screenHeight = 650;
    initwindow(screenWidth, screenHeight, "CGM Lab Assignment 2 - DDA Line Algorithm | Srishtee Dayma (104)");

    // Background setup
    setbkcolor(BLACK);
    cleardevice();

    // -------------------------------------------------------------------------
    // 1. OUTER BORDER & CANVAS FRAMING
    // -------------------------------------------------------------------------
    setcolor(DARKGRAY);
    rectangle(10, 10, screenWidth - 10, screenHeight - 10);
    rectangle(12, 12, screenWidth - 12, screenHeight - 12);

    // -------------------------------------------------------------------------
    // 2. HEADER BANNER
    // -------------------------------------------------------------------------
    setcolor(LIGHTCYAN);
    rectangle(18, 18, screenWidth - 18, 85);

    settextjustify(CENTER_TEXT, TOP_TEXT);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(screenWidth / 2, 26, const_cast<char*>("CGM LAB ASSIGNMENT 2: DDA LINE ALGORITHM"));

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(YELLOW);
    outtextxy(screenWidth / 2, 56, const_cast<char*>("Student: Srishtee Dayma  |  Roll No: 104  |  Batch: IC-2k24  |  Algorithm: Digital Differential Analyzer"));

    // -------------------------------------------------------------------------
    // 3. MAIN GRAPHICAL CANVAS (Left Side: X 20 to 520, Y 95 to 585)
    // -------------------------------------------------------------------------
    int canvasLeft = 20, canvasTop = 95, canvasRight = 520, canvasBottom = 585;
    setcolor(DARKGRAY);
    rectangle(canvasLeft, canvasTop, canvasRight, canvasBottom);

    // Canvas Background Grid Lines (Subtle reference grid)
    setcolor(COLOR(30, 35, 45));
    for (int gx = canvasLeft + 50; gx < canvasRight; gx += 50) {
        line(gx, canvasTop + 1, gx, canvasBottom - 1);
    }
    for (int gy = canvasTop + 50; gy < canvasBottom; gy += 50) {
        line(canvasLeft + 1, gy, canvasRight - 1, gy);
    }

    // Canvas Title
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setcolor(CYAN);
    outtextxy(canvasLeft + 10, canvasTop + 8, const_cast<char*>("GRAPHICAL CANVAS (Pixel-by-Pixel DDA Plots)"));

    // Define and draw test lines using DDA Line Algorithm
    std::vector<DDAStats> lineList;

    // Line 1: Gentle Slope (0 < m < 1) - Cyan
    lineList.push_back(drawDDALine("Line A (0 < m < 1)", 60, 520, 480, 310, CYAN));

    // Line 2: Steep Slope (m > 1) - Yellow
    lineList.push_back(drawDDALine("Line B (m > 1)", 80, 540, 220, 160, YELLOW));

    // Line 3: Negative Slope (m < 0) - Light Magenta
    lineList.push_back(drawDDALine("Line C (m < 0)", 220, 160, 480, 480, LIGHTMAGENTA));

    // Line 4: Horizontal (m = 0) - Light Green
    lineList.push_back(drawDDALine("Line D (m = 0)", 60, 550, 480, 550, LIGHTGREEN));

    // Line 5: Vertical (m = INF) - Light Red
    lineList.push_back(drawDDALine("Line E (m = INF)", 50, 160, 50, 520, LIGHTRED));

    // Annotate Line Endpoints and Labels on Canvas
    for (size_t i = 0; i < lineList.size(); ++i) {
        const DDAStats& s = lineList[i];
        drawEndpointMarker(s.x1, s.y1, s.color);
        drawEndpointMarker(s.x2, s.y2, s.color);

        char startLbl[40], endLbl[40], lineTag[40];
        std::sprintf(startLbl, "(%d,%d)", s.x1, s.y1);
        std::sprintf(endLbl, "(%d,%d)", s.x2, s.y2);
        std::sprintf(lineTag, "%s", s.name.c_str());

        setcolor(s.color);
        settextjustify(LEFT_TEXT, TOP_TEXT);

        // Position offset logic for readability
        if (i == 0) { // Line A
            outtextxy(s.x1 + 8, s.y1 - 15, startLbl);
            outtextxy(s.x2 - 60, s.y2 - 18, endLbl);
            outtextxy((s.x1 + s.x2)/2 + 10, (s.y1 + s.y2)/2 - 15, lineTag);
        } else if (i == 1) { // Line B
            outtextxy(s.x1 + 10, s.y1 - 10, startLbl);
            outtextxy(s.x2 - 10, s.y2 - 18, endLbl);
            outtextxy(s.x1 + 25, s.y1 - 120, lineTag);
        } else if (i == 2) { // Line C
            outtextxy(s.x2 + 8, s.y2 - 8, endLbl);
            outtextxy(s.x1 + 80, s.y1 + 120, lineTag);
        } else if (i == 3) { // Line D
            outtextxy(s.x2 - 65, s.y2 + 8, endLbl);
            outtextxy(s.x1 + 150, s.y1 + 8, lineTag);
        } else if (i == 4) { // Line E
            outtextxy(s.x1 - 40, s.y1 - 18, startLbl);
            outtextxy(s.x1 - 15, s.y1 + 180, lineTag);
        }
    }

    // -------------------------------------------------------------------------
    // 4. DDA CALCULATION PARAMETERS TABLE (Right Top: X 535 to 880, Y 95 to 375)
    // -------------------------------------------------------------------------
    int tblLeft = 535, tblTop = 95, tblRight = 880, tblBottom = 375;
    setcolor(LIGHTGRAY);
    rectangle(tblLeft, tblTop, tblRight, tblBottom);

    setcolor(YELLOW);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    outtextxy(tblLeft + 10, tblTop + 10, const_cast<char*>("DDA CALCULATION PARAMETERS TABLE"));

    setcolor(DARKGRAY);
    line(tblLeft + 10, tblTop + 28, tblRight - 10, tblTop + 28);

    // Table Column Headers
    setcolor(WHITE);
    outtextxy(tblLeft + 10,  tblTop + 35, const_cast<char*>("Line ID"));
    outtextxy(tblLeft + 115, tblTop + 35, const_cast<char*>("dx"));
    outtextxy(tblLeft + 160, tblTop + 35, const_cast<char*>("dy"));
    outtextxy(tblLeft + 205, tblTop + 35, const_cast<char*>("Steps"));
    outtextxy(tblLeft + 255, tblTop + 35, const_cast<char*>("xInc"));
    outtextxy(tblLeft + 300, tblTop + 35, const_cast<char*>("yInc"));

    setcolor(DARKGRAY);
    line(tblLeft + 10, tblTop + 52, tblRight - 10, tblTop + 52);

    // Populate Table Rows
    int rowY = tblTop + 60;
    for (size_t i = 0; i < lineList.size(); ++i) {
        const DDAStats& s = lineList[i];
        setcolor(s.color);

        char colID[30], colDx[20], colDy[20], colSteps[20], colXinc[20], colYinc[20];
        std::sprintf(colID, "%s", s.name.substr(0, 11).c_str());
        std::sprintf(colDx, "%.0f", s.dx);
        std::sprintf(colDy, "%.0f", s.dy);
        std::sprintf(colSteps, "%d", s.steps);
        std::sprintf(colXinc, "%.2f", s.xInc);
        std::sprintf(colYinc, "%.2f", s.yInc);

        outtextxy(tblLeft + 10,  rowY, colID);
        outtextxy(tblLeft + 115, rowY, colDx);
        outtextxy(tblLeft + 160, rowY, colDy);
        outtextxy(tblLeft + 205, rowY, colSteps);
        outtextxy(tblLeft + 255, rowY, colXinc);
        outtextxy(tblLeft + 300, rowY, colYinc);

        rowY += 24;
    }

    setcolor(DARKGRAY);
    line(tblLeft + 10, rowY + 5, tblRight - 10, rowY + 5);

    // Algorithm Formula Box
    rowY += 15;
    setcolor(LIGHTCYAN);
    outtextxy(tblLeft + 10, rowY, const_cast<char*>("DDA Algorithm Formulations:"));
    rowY += 18;
    setcolor(LIGHTGRAY);
    outtextxy(tblLeft + 15, rowY, const_cast<char*>("1. dx = x2 - x1 ,  dy = y2 - y1"));
    rowY += 16;
    outtextxy(tblLeft + 15, rowY, const_cast<char*>("2. steps = max(|dx|, |dy|)"));
    rowY += 16;
    outtextxy(tblLeft + 15, rowY, const_cast<char*>("3. xInc = dx / steps ,  yInc = dy / steps"));
    rowY += 16;
    outtextxy(tblLeft + 15, rowY, const_cast<char*>("4. Pixel Plot: ( round(x) , round(y) )"));

    // -------------------------------------------------------------------------
    // 5. MAGNIFIED PIXEL GRID INSET (Right Bottom: X 535 to 880, Y 390 to 585)
    // -------------------------------------------------------------------------
    int gridLeft = 535, gridTop = 390, gridRight = 880, gridBottom = 585;
    setcolor(LIGHTGRAY);
    rectangle(gridLeft, gridTop, gridRight, gridBottom);

    setcolor(GREEN);
    outtextxy(gridLeft + 10, gridTop + 8, const_cast<char*>("MAGNIFIED PIXEL STEP DEMONSTRATION"));

    setcolor(LIGHTGRAY);
    outtextxy(gridLeft + 10, gridTop + 24, const_cast<char*>("Step-by-step rasterization (Line A excerpt):"));

    // Draw magnified grid (8x8 cells)
    int cellStartX = gridLeft + 20;
    int cellStartY = gridTop + 45;
    int cellSize = 16;
    int cols = 12, rows = 7;

    setcolor(COLOR(50, 60, 70));
    for (int r = 0; r <= rows; ++r) {
        line(cellStartX, cellStartY + r * cellSize, cellStartX + cols * cellSize, cellStartY + r * cellSize);
    }
    for (int c = 0; c <= cols; ++c) {
        line(cellStartX + c * cellSize, cellStartY, cellStartX + c * cellSize, cellStartY + rows * cellSize);
    }

    // Simulate DDA line points on grid (x1=0, y1=6 to x2=11, y2=1)
    float sampleX = 0, sampleY = 6;
    float sampleDx = 11, sampleDy = -5;
    int sampleSteps = 11;
    float sampleXinc = sampleDx / sampleSteps;
    float sampleYinc = sampleDy / sampleSteps;

    for (int s = 0; s <= sampleSteps; ++s) {
        int px = static_cast<int>(round(sampleX));
        int py = static_cast<int>(round(sampleY));

        // Fill cell
        setfillstyle(SOLID_FILL, CYAN);
        bar(cellStartX + px * cellSize + 2, cellStartY + py * cellSize + 2,
            cellStartX + (px + 1) * cellSize - 2, cellStartY + (py + 1) * cellSize - 2);

        sampleX += sampleXinc;
        sampleY += sampleYinc;
    }

    setcolor(YELLOW);
    outtextxy(gridLeft + 10, gridBottom - 20, const_cast<char*>("* Filled squares show discrete rounded pixel positions"));

    // -------------------------------------------------------------------------
    // 6. FOOTER STATUS BAR
    // -------------------------------------------------------------------------
    settextjustify(CENTER_TEXT, TOP_TEXT);
    setcolor(LIGHTGRAY);
    outtextxy(screenWidth / 2, 600, const_cast<char*>("CGM Lab Assignment 2 DDA Line output created. Press any key to exit."));

    // Save output screenshot image
    writeimagefile("output.png", 0, 0, screenWidth, screenHeight);

    // Wait for keypress if non-automated
    if (!autoExit) {
        getch();
    }

    closegraph();
    return 0;
}
