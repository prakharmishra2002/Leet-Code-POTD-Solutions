class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        answer = [0] * len(boxes)
        for current_box in range(len(boxes)):
            # If the current box contains a ball, calculate the number of moves for every box.
            if boxes[current_box] == "1":
                for new_position in range(len(boxes)):
                    answer[new_position] += abs(new_position - current_box)
        return answer
