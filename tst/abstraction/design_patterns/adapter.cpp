#include "gmock/gmock.h"

#include "adapter.h"

using testing::HasSubstr;

namespace design_patterns
{

class MockRectangleAdapter : public RectangleAdapter
{
public:
	MockRectangleAdapter(int x, int y, int w, int h) : RectangleAdapter(x, y, w, h) {}
};

TEST(AdapterTest, ShouldCallMethodThroughAdapter)
{
	// GIVEN
	std::unique_ptr<IRectangle> r = std::make_unique<MockRectangleAdapter>(120, 200, 60, 40);

	// WHEN
	testing::internal::CaptureStdout();
	r->Draw();

	// THEN
	ASSERT_THAT(::testing::internal::GetCapturedStdout().c_str(), HasSubstr("RectangleAdapter: draw."));
};

}