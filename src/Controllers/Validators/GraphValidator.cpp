#include <GraphValidator.h>



bool GraphValidator::Validate(const GraphInput &input) {
    bool status = true;

    if (input.countPoints <= 0) {
        status = false;
    } else if (input.xMax < input.xMin) {
        status = false;
    } else if (input.yMax < input.yMin) {
        status = false;
    }
    return status;
}
