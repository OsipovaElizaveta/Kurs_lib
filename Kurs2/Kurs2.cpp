#include <libs/rapidcsv/rapidcsv.h>
#include <libs/idflow/idflow.hpp>

using namespace idflow;

int main()
{
	rapidcsv::Document doc("data.csv", rapidcsv::LabelParams(-1, -1), rapidcsv::SeparatorParams(';'));

	vector<pair<string, string>> data;

	for (size_t i = 0; i < doc.GetRowCount(); i++)
		data.push_back({ doc.GetCell<string>(0, i), doc.GetCell<string>(1, i) });

	Mat image;

	Scalar redColor(0, 0, 255);
	Scalar greenColor(0, 255, 0);

	IDFlowParams params = IDFlowParams();
	params.ImageWidth = 1160;
	params.ImageHeight = 620;
	params.InGroups = { pair("Erroneous", redColor), pair("Urgent, not important", greenColor), pair("Urgent", greenColor), pair("Important", greenColor) };
	params.OutGroups = { pair("Lost", redColor), pair("Forgotten", redColor), pair("Erroneous", redColor), pair("Not submitted on time", redColor), pair("Submitted on time without errors", greenColor) };
	params.FigureWidth = 225;
	params.HorizontalSpacing = 225;
	params.VerticalSpacing = 32;
	params.BgColor = Scalar(230, 230, 230);
	params.FigureColor = COLOR_ROYAL_BLUE;
	params.Padding = 16;
	params.TextOffset = 4;
	params.FontSize = 0.4;
	params.Font = FONT_HERSHEY_SIMPLEX;

	IDFlowMaker maker(params);
	maker.createFlow(image, data, "All Orders", 3.5);

	imshow("kurs02", image);
	waitKey();

	destroyAllWindows();
	return 0;
}