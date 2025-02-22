// idflow
//
// version 0.1.1
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 Elizaveta Osipova <lizaosipova200211@gmail.com>.
//
// Permission is hereby  granted, free of charge, to any  person obtaining a copy
// of this software and associated  documentation files (the "Software"), to deal
// in the Software  without restriction, including without  limitation the rights
// to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
// copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
// IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
// FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
// AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace idflow {

	/**
	 * @brief cv::Scalar instance representing rgb(220,220,220) color
	 */
	const Scalar COLOR_GAINSBORO(220, 220, 220);
	/**
	 * @brief cv::Scalar instance representing rgb(255,165,220) color
	 */
	const Scalar COLOR_ORANGE(0, 165, 255);
	/**
	 * @brief cv::Scalar instance representing rgb(65,105,255) color
	 */
	const Scalar COLOR_ROYAL_BLUE(255, 105, 65);
	/**
	 * @brief cv::Scalar instance representing rgb(34,139,34) color
	 */
	const Scalar COLOR_FOREST_GREEN(34, 139, 34);
	/**
	 * @brief cv::Scalar instance representing rgb(250,220,114) color
	 */
	const Scalar COLOR_SALMON(114, 128, 250);
	/**
	 * @brief cv::Scalar instance representing rgb(220,20,60) color
	 */
	const Scalar COLOR_CRIMSON(60, 20, 220);
	/**
	 * @brief cv::Scalar instance representing rgb(0,0,0) color
	 */
	const Scalar COLOR_BLACK(0, 0, 0);
	/**
	 * @brief cv::Scalar instance representing rgb(255,255,255) color
	 */
	const Scalar COLOR_WHITE(255, 255, 255);

	/**
	 * @brief Inter-dimensional flow parameters for IDFlowMaker class
	 */
	class IDFlowParams {

	public:
#if defined(_MSC_VER)
#pragma warning (push)
#pragma warning (disable: 26495)
#endif
		/**
		 * @brief IDFlowParams instance constructor
		 * @param pImageWidth Total width (in pixels) or resulting matrix (image). If the value provided is less than or equal to 0, resulting width will be calculated automatically
		 * @param pImageHeight Total height (in pixels) or resulting matrix (image). If the value provided is less than or equal to 0, resulting height will be calculated automatically
		 * @param pInGroups Order and colors of rectangles on the left side of inter-dimensional flow. If the value from the data source is present in the order list then it will take precedence.
		 *		  Otherwise the order will be as in the data source.
		 * @param pOutGroups Order and colors of rectangles on the right side of inter-dimensional flow. If the value from the data source is present in the order list then it will take precedence.
		 *		  Otherwise the order will be as in the data source.
		 * @param pFigureWidth Width (in pixels) of rectangles
		 * @param pHorizontalSpacing Horizontal distance (in pixels) between rectangles
		 * @param pVerticalSpacing Vertical distance (in pixels) between rectangles
		 * @param pBgColor Instance of cv::Scalar class used as a background color of the resulting image
		 * @param pFigureColor Instance of cv::Scalar class used as a default rectangle color
		 * @param pPadding Horizontal and vertical distances between the edges of resulting matrix (image) and rectangles
		 * @param pTextOffset Distance between edges of rectangles and their inner text labels
		 * @param pFontSize Font size of all text labels
		 * @param pFont Font (from cv::HersheyFonts enum) of all text labels
		 */
		explicit IDFlowParams(const int pImageWidth = 0,
			const int pImageHeight = 0,
			const vector<pair<string, Scalar>> pInGroups = vector<pair<string, Scalar>>(),
			const vector<pair<string, Scalar>> pOutGroups = vector<pair<string, Scalar>>(),
			const int pFigureWidth = 250,
			const int pHorizontalSpacing = 250,
			const int pVerticalSpacing = 40,
			const Scalar pBgColor = COLOR_GAINSBORO,
			const Scalar pFigureColor = COLOR_ROYAL_BLUE,
			const int pPadding = 20,
			const int pTextOffset = 3,
			const double pFontSize = 0.4,
			const HersheyFonts pFont = FONT_HERSHEY_SIMPLEX) {

			ImageWidth = pImageWidth;
			ImageHeight = pImageHeight;
			InGroups = pInGroups;
			OutGroups = pOutGroups;
			FigureWidth = pFigureWidth;
			HorizontalSpacing = pHorizontalSpacing;
			VerticalSpacing = pVerticalSpacing;
			BgColor = pBgColor;
			FigureColor = pFigureColor;
			Padding = pPadding;
			TextOffset = pTextOffset;
			FontSize = pFontSize;
			Font = pFont;
		}
#if defined(_MSC_VER)
#pragma warning (pop)
#endif

		/**
		 * @brief ImageWidth property setter
		 * @param pImageWidth New value
		 */
		void putImageWidth(int pImageWidth) { mImageWidth = pImageWidth; }
		/**
		 * @brief ImageWidth property getter
		 * @return ImageWidth value
		 */
		int getImageWidth() { return mImageWidth; }
		/**
		 * @brief ImageHeight property setter
		 * @param pImageHeight New value
		 */
		void putImageHeight(int pImageHeight) { mImageHeight = pImageHeight; }
		/**
		 * @brief ImageHeight property getter
		 * @return ImageHeight value
		 */
		int getImageHeight() { return mImageHeight; }
		/**
		 * @brief InsOrder property setter
		 * @param pInsOrder New value
		 */
		void putInGroups(vector<pair<string, Scalar>> pInsOrder) { mInGroups = pInsOrder; }
		/**
		 * @brief InsOrder property getter
		 * @return InsOrder value
		 */
		vector<pair<string, Scalar>> getInGroups() { return mInGroups; }
		/**
		 * @brief OutsOrder property setter
		 * @param pOutsOrder New value
		 */
		void putOutGroups(vector<pair<string, Scalar>> pOutsOrder) { mOutGroups = pOutsOrder; }
		/**
		 * @brief OutsOrder property getter
		 * @return OutsOrder value
		 */
		vector<pair<string, Scalar>> getOutGroups() { return mOutGroups; }
		/**
		 * @brief FigureWidth property setter
		 * @param pFigureWidth New positive value
		 */
		void putFigureWidth(int pFigureWidth) {
			if (pFigureWidth <= 0)
				throw invalid_argument("Figure width must be greater than 0");
			mFigureWidth = pFigureWidth;
		}
		/**
		 * @brief FigureWidth property getter
		 * @return FigureWidth value
		 */
		int getFigureWidth() { return mFigureWidth; }
		/**
		 * @brief HorizontalSpacing property setter
		 * @param pHorizontalSpacing New positive value
		 */
		void putHorizontalSpacing(int pHorizontalSpacing) {
			if (pHorizontalSpacing <= 0)
				throw invalid_argument("Horizontal spacing must be greater than 0");
			mHorizontalSpacing = pHorizontalSpacing;
		}
		/**
		 * @brief HorizontalSpacing property getter
		 * @return HorizontalSpacing value
		 */
		int getHorizontalSpacing() { return mHorizontalSpacing; }
		/**
		 * @brief VerticalSpacing property setter
		 * @param pVerticalSpacing New positive value
		 */
		void putVerticalSpacing(int pVerticalSpacing) {
			if (pVerticalSpacing <= 0)
				throw invalid_argument("Vertical spacing must be greater than 0");
			mVerticalSpacing = pVerticalSpacing;
		}
		/**
		 * @brief VerticalSpacing property getter
		 * @return VerticalSpacing value
		 */
		int getVerticalSpacing() { return mVerticalSpacing; }
		/**
		 * @brief BgColor property setter
		 * @param pBgColor New value
		 */
		void putBgColor(Scalar pBgColor) { mBgColor = pBgColor; }
		/**
		 * @brief BgColor property getter
		 * @return BgColor value
		 */
		Scalar getBgColor() { return mBgColor; }
		/**
		 * @brief FigureColor property setter
		 * @param pFigureColor New value
		 */
		void putFigureColor(Scalar pFigureColor) { mFigureColor = pFigureColor; }
		/**
		 * @brief FigureColor property getter
		 * @return FigureColor value
		 */
		Scalar getFigureColor() { return mFigureColor; }
		/**
		 * @brief Padding property setter
		 * @param pPadding New non-negative value
		 */
		void putPadding(int pPadding) {
			if (pPadding < 0)
				throw invalid_argument("Padding must be greater than or equal to 0");
			mPadding = pPadding;
		}
		/**
		 * @brief Padding property getter
		 * @return Padding value
		 */
		int getPadding() { return mPadding; }
		/**
		 * @brief TextOffset property setter
		 * @param pTextOffset New non-negative value
		 */
		void putTextOffset(int pTextOffset) {
			if (pTextOffset < 0)
				throw invalid_argument("Text offset must be greater than or equal to 0");
			mTextOffset = pTextOffset;
		}
		/**
		 * @brief TextOffset property getter
		 * @return TextOffset value
		 */
		int getTextOffset() { return mTextOffset; }
		/**
		 * @brief FontSize property setter
		 * @param pFontSize New positive value
		 */
		void putFontSize(double pFontSize) {
			if (pFontSize <= 0)
				throw invalid_argument("Font size must be greater than 0");
			mFontSize = pFontSize;
		}
		/**
		 * @brief FontSize property getter
		 * @return FontSize value
		 */
		double getFontSize() { return mFontSize; }
		/**
		 * @brief Font property setter
		 * @param pFont New value from cv::HersheyFonts enum
		 */
		void putFont(HersheyFonts pFont) { mFont = pFont; }
		/**
		 * @brief Font property getter
		 * @return Font value
		 */
		HersheyFonts getFont() { return mFont; }
		/**
		 * @brief Total width (in pixels) or resulting matrix (image). If the value provided is less than or equal to 0, resulting width will be calculated automatically
		 */
		__declspec(property(get = getImageWidth, put = putImageWidth)) int ImageWidth;
		/**
		 * @brief Total height (in pixels) or resulting matrix (image). If the value provided is less than or equal to 0, resulting height will be calculated automatically
		 */
		__declspec(property(get = getImageHeight, put = putImageHeight)) int ImageHeight;
		/**
		 * @brief Order and colors of rectangles on the left side of inter-dimensional flow. If the value from the data source is present in the order list then it will take precedence.
		 *		  Otherwise the order will be as in the data source.
		 */
		__declspec(property(get = getInGroups, put = putInGroups)) vector<pair<string, Scalar>> InGroups;
		/**
		 * @brief Order and colors of rectangles on the right side of inter-dimensional flow. If the value from the data source is present in the order list then it will take precedence.
		 *		  Otherwise the order will be as in the data source.
		 */
		__declspec(property(get = getOutGroups, put = putOutGroups)) vector<pair<string, Scalar>> OutGroups;
		/**
		 * @brief Width (in pixels) of rectangles
		 */
		__declspec(property(get = getFigureWidth, put = putFigureWidth)) int FigureWidth;
		/**
		 * @brief Horizontal distance (in pixels) between rectangles
		 */
		__declspec(property(get = getHorizontalSpacing, put = putHorizontalSpacing)) int HorizontalSpacing;
		/**
		 * @brief Vertical distance (in pixels) between rectangles
		 */
		__declspec(property(get = getVerticalSpacing, put = putVerticalSpacing)) int VerticalSpacing;
		/**
		 * @brief Instance of cv::Scalar class used as a background color of the resulting image
		 */
		__declspec(property(get = getBgColor, put = putBgColor)) Scalar BgColor;
		/**
		 * @brief Instance of cv::Scalar class used as a default rectangle color
		 */
		__declspec(property(get = getFigureColor, put = putFigureColor)) Scalar FigureColor;
		/**
		 * @brief Horizontal and vertical distances between the edges of resulting matrix (image) and rectangles
		 */
		__declspec(property(get = getPadding, put = putPadding)) int Padding;
		/**
		 * @brief Distance between edges of rectangles and their inner text labels
		 */
		__declspec(property(get = getTextOffset, put = putTextOffset)) int TextOffset;
		/**
		 * @brief Font size of all text labels
		 */
		__declspec(property(get = getFontSize, put = putFontSize)) double FontSize;
		/**
		 * @brief Font (from cv::HersheyFonts enum) of all text labels
		 */
		__declspec(property(get = getFont, put = putFont)) HersheyFonts Font;

	private:

		int mImageWidth;
		int mImageHeight;
		vector<pair<string, Scalar>> mInGroups;
		vector<pair<string, Scalar>> mOutGroups;
		int mFigureWidth;
		int mHorizontalSpacing;
		int mVerticalSpacing;
		Scalar mBgColor;
		Scalar mFigureColor;
		int mPadding;
		int mTextOffset;
		double mFontSize;
		HersheyFonts mFont;
	};

	/**
	 * @brief Inter-dimensional flow maker
	 */
	class IDFlowMaker {
	public:
		/**
		 * @brief IDFlowMaker instance constructor
		 * @param pParams Instance of IDFlowParams class used to create inter-dimensional flows
		 */
		explicit IDFlowMaker(const IDFlowParams& pParams) : mParams(pParams) {}

		/**
		 * @brief Create an inter-dimensional flow based on provided to this function parameters and the data from the IDFlowParams class
		 * @param image Output matrix (image) containing the inter-dimensional flow
		 * @param data A vector of pairs of strings which is used as a source of data
		 * @param totalLabel A string that is used as a header for the middle section of inter-dimensional flow
		 * @param countPerPixel A fractional number used as a denominator when calculating the height or resulting rectangles on the inter-dimensional flow
		 */
		void createFlow(
			Mat& image,
			const vector<pair<string, string>> data,
			const string totalLabel,
			const double countPerPixel) {

			if (data.size() == 0)
				throw length_error("Data can not be empty");
			if (totalLabel.empty())
				throw length_error("Total label can not be empty");
			if (countPerPixel <= 0)
				throw invalid_argument("Count per pixel must be greater than 0");

			vector<string> ins;
			vector<string> outs;

			for (const pair p : data)
				ins.push_back(p.first);
			for (const pair p : data)
				outs.push_back(p.second);

			const Scalar rectangleColor = mParams.FigureColor;

			vector<IDFlowGroup> inGroups;
			vector<IDFlowGroup> outGroups;
			countValuesAndReorder(inGroups, ins, mParams.InGroups, rectangleColor);
			countValuesAndReorder(outGroups, outs, mParams.OutGroups, rectangleColor);

			map<Scalar, int, ScalarCompare> inColorToTotalCount;
			map<Scalar, int, ScalarCompare> outColorToTotalCount;

			for (const IDFlowGroup value : inGroups)
				inColorToTotalCount[value.Color] += value.Count;
			for (const IDFlowGroup value : outGroups)
				outColorToTotalCount[value.Color] += value.Count;

			int imgWidth = mParams.ImageWidth;
			int imgHeight = mParams.ImageHeight;

			if (imgWidth <= 0)
				imgWidth = 3 * mParams.FigureWidth + 2 * mParams.HorizontalSpacing + 2 * mParams.Padding;

			if (imgHeight <= 0) {
				const auto& list = inGroups.size() >= outGroups.size() ? inGroups : outGroups;
				imgHeight = (list.size() - 1) * mParams.VerticalSpacing + 2 * mParams.Padding;
				for (const auto& p : list)
					imgHeight += p.Count / countPerPixel;
			}

			image = Mat(imgHeight, imgWidth, IMAGE_TYPE, mParams.BgColor);

			int verticalRectangleOffset = mParams.Padding;
			int horizontalOffset = mParams.Padding;
			int verticalCurveOffset = mParams.Padding;

			const int totalHeight = max(static_cast<int>(data.size() / countPerPixel), MINIMUM_FIGURE_HEIGHT);

			for (size_t i = 0, size = inGroups.size(); i < size; i++) {
				const auto p = inGroups[i];
				const int initialHeight = p.Count / countPerPixel;
				const int height = max(initialHeight, MINIMUM_FIGURE_HEIGHT);
				const int curveEndHeight = i == size - 1 ? (totalHeight + mParams.Padding - verticalCurveOffset) : initialHeight;
				const Scalar recColor = applyAlpha(p.Color, mParams.BgColor, getAlpha(p.Count, inColorToTotalCount[p.Color]));

				drawRectangle(image, horizontalOffset, verticalRectangleOffset, mParams.FigureWidth, height, recColor, p.Name, to_string(p.Count), mParams.FontSize, mParams.Font, mParams.TextOffset);
				drawFilledCurve(image, Point2d(horizontalOffset + mParams.FigureWidth, verticalRectangleOffset), Point2d(horizontalOffset + mParams.FigureWidth + mParams.HorizontalSpacing, verticalCurveOffset), height, curveEndHeight, recColor, rectangleColor);

				verticalRectangleOffset += height + mParams.VerticalSpacing;
				verticalCurveOffset += curveEndHeight;
			}

			verticalRectangleOffset = mParams.Padding;
			horizontalOffset += mParams.FigureWidth + mParams.HorizontalSpacing;

			drawRectangle(image, horizontalOffset, verticalRectangleOffset, mParams.FigureWidth, totalHeight, rectangleColor, totalLabel, to_string(data.size()), mParams.FontSize, mParams.Font, mParams.TextOffset);

			verticalRectangleOffset = mParams.Padding;
			horizontalOffset += mParams.FigureWidth + mParams.HorizontalSpacing;
			verticalCurveOffset = mParams.Padding;

			for (size_t i = 0, size = outGroups.size(); i < size; i++) {
				const auto p = outGroups[i];
				const int initialHeight = p.Count / countPerPixel;
				const int height = max(initialHeight, MINIMUM_FIGURE_HEIGHT);
				const int curveEndHeight = i == size - 1 ? (totalHeight + mParams.Padding - verticalCurveOffset) : initialHeight;
				const Scalar recColor = applyAlpha(p.Color, mParams.BgColor, getAlpha(p.Count, outColorToTotalCount[p.Color]));

				drawRectangle(image, horizontalOffset, verticalRectangleOffset, mParams.FigureWidth, height, recColor, p.Name, to_string(p.Count), mParams.FontSize, mParams.Font, mParams.TextOffset);
				drawFilledCurve(image, Point2d(horizontalOffset, verticalRectangleOffset), Point2d(horizontalOffset - mParams.HorizontalSpacing, verticalCurveOffset), height, curveEndHeight, recColor, rectangleColor);

				verticalRectangleOffset += height + mParams.VerticalSpacing;
				verticalCurveOffset += curveEndHeight;
			}
		}

	private:
		static const int IMAGE_TYPE = CV_8UC3;
		static const int MINIMUM_FIGURE_HEIGHT = 20;
		static constexpr double MINIMUM_ALPHA = 0.25;

		IDFlowParams mParams;

		class IDFlowGroup {
		public:
			string Name;
			int Count;
			Scalar Color;
			explicit IDFlowGroup(string name, int count, Scalar color) {
				Name = name;
				Count = count;
				Color = color;
			}
		};

		struct ScalarCompare {
			bool operator() (const Scalar& lhs, const Scalar& rhs) const {
				return (lhs[0] + lhs[1] * 256 + lhs[2] * 256 * 256) < (rhs[0] + rhs[1] * 256 + rhs[2] * 256 * 256);
			}
		};

		static void drawRectangle(Mat& image, const int x, const int y, const int width, const int height, const Scalar bgColor, const string topLeftText, const string bottomRightText, const double fontSize, const int font, const int offset) {
			Mat rect(height, width, IMAGE_TYPE);
			rectangle(rect, Rect(0, 0, image.cols, image.rows), bgColor, FILLED);

			Scalar textColor = getContrastColor(bgColor);

			const Size topLeftTextSize = getTextSize(topLeftText, font, fontSize, 1, NULL);
			putText(rect, topLeftText, Point2d(offset, topLeftTextSize.height + offset), font, fontSize, textColor, 1, LINE_AA);

			const Size2i bottomRightTextSize = getTextSize(bottomRightText, font, fontSize, 1, NULL);
			putText(rect, bottomRightText, Point2d(width - bottomRightTextSize.width - offset, height - offset - 2), font, fontSize, textColor, 1, LINE_AA);

			rect.copyTo(image(Rect(x, y, rect.cols, rect.rows)));
		}

		static double solveCubicEquation(double t, double a, double b, double c, double d) {
			return pow(1 - t, 3) * a + 3 * t * pow(1 - t, 2) * b + 3 * pow(t, 2) * (1 - t) * c + pow(t, 3) * d;
		}

		static void getCurvePoints(vector<Point2d>& points, const Point2d p0, const Point2d p3) {
			const Point2d p1(p0.x + (p3.x - p0.x) / 3, p0.y);
			const Point2d p2(p0.x + (p3.x - p0.x) * 2 / 3, p3.y);

			const int l = abs(p3.x - p0.x);

			for (double i = 0; i <= l; i++)
			{
				const double t = i / l;
				auto x = solveCubicEquation(t, p0.x, p1.x, p2.x, p3.x);
				auto y = solveCubicEquation(t, p0.y, p1.y, p2.y, p3.y);
				points.push_back(Point2d(x, y));
			}
		}

		static void drawFilledCurve(const Mat& img, const Point2d p0, const Point2d p3, const int leftHeight, const int rightHeight, const Scalar startColor, const Scalar endColor) {

			vector<Point2d> topPoints;
			vector<Point2d> bottomPoints;

			getCurvePoints(topPoints, p0, p3);
			getCurvePoints(bottomPoints, Point2d(p0.x, p0.y + leftHeight - 1), Point2d(p3.x, p3.y + rightHeight - 1));

			int size = topPoints.size();

			for (size_t i = 0; i < size; i++)
				line(img, topPoints[i], bottomPoints[i], applyAlpha(startColor, endColor, 1 - ((double)i / (size - 1))));
		}

		static void countValuesAndReorder(vector<IDFlowGroup>& result, const vector<string> source, const vector<pair<string, Scalar>> order, const Scalar defaultColor) {

			map<string, int> nameToOrder;
			map<string, int> nameToCount;
			map<string, Scalar> nameToColor;

			for (const pair<string, Scalar> value : order)
				nameToColor[value.first] = value.second;

			for (const string value : source)
				if (nameToCount.contains(value))
					nameToCount[value] += 1;
				else {
					nameToOrder[value] = nameToOrder.size();
					nameToCount[value] = 1;
				}

			for (size_t i = 0, size = order.size(); i < size; i++)
			{
				string name = order[i].first;
				if (nameToOrder.contains(name) && nameToOrder[name] >= 0)
					nameToOrder[name] = i - size;
			}

			vector<pair<string, int>> nameToOrderVec(nameToOrder.begin(), nameToOrder.end());
			sort(nameToOrderVec.begin(), nameToOrderVec.end(), [](auto a, auto b) { return b.second > a.second; });
			for (const pair p : nameToOrderVec)
				result.push_back(IDFlowGroup(p.first, nameToCount[p.first], nameToColor.contains(p.first) ? nameToColor[p.first] : defaultColor));
		}

		static double getAlpha(int count, int totalCount) {
			return ((1 - MINIMUM_ALPHA) * count / totalCount) + MINIMUM_ALPHA;
		}

		static Scalar applyAlpha(Scalar fgColor, Scalar bgColor, double alpha) {
			Scalar result;

			for (size_t i = 0; i <= 2; i++)
				result[i] = alpha * fgColor[i] + (1 - alpha) * bgColor[i];

			return result;
		}

		static Scalar getContrastColor(Scalar color) {
			double luma = ((0.114 * color[0]) + (0.587 * color[1]) + (0.299 * color[2])) / 255;
			return luma > 0.5 ? COLOR_BLACK : COLOR_WHITE;
		}
	};
}