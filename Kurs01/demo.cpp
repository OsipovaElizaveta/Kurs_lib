#include <idflow.hpp>

using namespace idflow;

int main()
{
	const vector<pair<string, string>> data = {
	 { "InputValue1", "OutputValue1" },
	 { "InputValue2", "OutputValue1" },
	 { "InputValue3", "OutputValue2" },
	 { "InputValue4", "OutputValue3" },
	 { "InputValue1", "OutputValue4" },
	 { "InputValue2", "OutputValue2" },
	 { "InputValue1", "OutputValue5" },
	 { "InputValue4", "OutputValue1" },
	 { "InputValue3", "OutputValue4" },
	 { "InputValue3", "OutputValue3" },
	 { "InputValue1", "OutputValue2" } };

	Mat image;

	IDFlowParams params = IDFlowParams();
	params.InGroups = { pair("InputValue3", COLOR_FOREST_GREEN), pair("InputValue4", COLOR_ROYAL_BLUE) };
	params.OutGroups = { pair("OutputValue4", COLOR_ROYAL_BLUE), pair("OutputValue3", COLOR_ROYAL_BLUE), pair("OutputValue2", COLOR_FOREST_GREEN) };
	params.FigureColor = COLOR_ORANGE;

	IDFlowMaker maker(params);
	maker.createFlow(image, data, "Total", 0.03);

	imshow("demo flow", image);
	waitKey();

	destroyAllWindows();
	return 0;
}