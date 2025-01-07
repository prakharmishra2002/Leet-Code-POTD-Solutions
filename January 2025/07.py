class Solution:
    def stringMatching(self, words):
        matching_words = []

        # Iterate through each word in the input list.
        for current_word_index in range(len(words)):
            # Compare the current word with all other words.
            for other_word_index in range(len(words)):
                # Skip comparing the word with itself.
                if current_word_index == other_word_index:
                    continue
                if words[current_word_index] in words[other_word_index]:
                    # Add it to the result list if true.
                    matching_words.append(words[current_word_index])
                    break  # No need to check further for this word.
        return matching_words
