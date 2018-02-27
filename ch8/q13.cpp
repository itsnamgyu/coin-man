#include <cstdio>
#include <vector>
#include <algorithm>

class Box {
	public:
		Box(FILE* stream) {
			fscanf(stream, "%d %d %d", &width, &height, &depth);
		}
		
		Box(int width, int height, int depth) {
			this->width = width;
			this->height = height;
			this->depth = depth;
		}
		
		void addIfSmaller(Box box) {
			if (box.width < width && box.height < height && box.depth < depth) {
				smallerBoxes.push_back(box);
			}
		}

		void print(FILE* stream) const {
			fprintf(stream, "box(%d, %d, %d)\n", width, height, depth);
		}

		void print() const {
			print(stdout);
		}

		const bool compareWith(Box box) {
			return this->height < box.height;
		}

		int index = 0;
		int height;
		int width;
		int depth;
		std::vector<Box> smallerBoxes;
};

int max(int a, int b);

int main(void) {
	int n;
	scanf("%d", &n);
	
	auto boxes = std::vector<Box>();
	for (int i = 0; i < n; ++i)
		boxes.push_back(Box(stdin));

	std::sort(boxes.begin(), boxes.end(), [] (Box boxA, Box boxB) { return !boxA.compareWith(boxB); });
	printf("Sorted boxes:\n");
	for (int i = 0; i < boxes.size(); ++i) {
		boxes[i].print();
		boxes[i].index = i;
	}

	for (int i = 0; i < boxes.size(); ++i)
		for (int j = i + 1; j < boxes.size(); ++j)
			boxes[i].addIfSmaller(boxes[j]);

	auto maxHeightTill = std::vector<int>(boxes.size(), 0);
	for (auto const& box : boxes) {
		int maxHeightNow = maxHeightTill[box.index];
		maxHeightNow = maxHeightTill[box.index] = max(maxHeightNow, box.height);

		for (auto const& smallerBox : box.smallerBoxes)
			maxHeightTill[smallerBox.index] = max(maxHeightTill[smallerBox.index], maxHeightNow + smallerBox.height);
	}

	int maxHeight = 0;
	for (int i = 0; i < maxHeightTill.size(); ++i) {
		maxHeight = max(maxHeight, maxHeightTill[i]);
		printf("Max height till %03d: %d\n", i, maxHeightTill[i]);
	}

	printf("Max height: %d\n", maxHeight);
}

int max(int a, int b) {
	return a < b ? b : a;
}
