#!/bin/bash

# Array of sample paragraphs for the files
sample_paragraphs=(
  "This is the first paragraph. It serves as an introduction to the collection of text files. Each file contains a unique sample of text, designed to represent different types of content."
  "The second paragraph introduces a new topic. Here we talk about how to organize content within files, and the importance of structure in making text easy to read and understand."
  "Paragraph three dives deeper into the process of content creation. The goal is to emphasize creativity and clarity when writing content for a broad audience."
  "In the fourth paragraph, we discuss the role of language in communication. Effective writing can bridge the gap between ideas and the people who need to understand them."
  "Fifth paragraph explores the relationship between text formatting and readability. How the visual presentation of words can affect how easily someone absorbs the information."
  "Paragraph six provides a brief overview of various writing styles. Each style can convey different tones and messages, depending on the intended audience and purpose."
  "The seventh paragraph talks about the evolution of writing tools. From typewriters to modern word processors, the way we write has changed dramatically over the years."
  "In the eighth paragraph, we discuss the importance of proofreading. The process of reviewing your work ensures that the final product is free of errors and effectively conveys your message."
  "Paragraph nine addresses the significance of feedback in writing. Feedback from others can help refine a piece of writing and improve the clarity and impact of the message."
  "The tenth and final paragraph wraps up the discussion. It recaps the main points covered in the previous paragraphs and emphasizes the value of good writing in everyday communication."
)

# Array of different file names
file_names=(
  "introduction.txt"
  "organization.txt"
  "content_creation.txt"
  "effective_communication.txt"
  "readability.txt"
  "writing_styles.txt"
  "writing_tools.txt"
  "proofreading.txt"
  "feedback.txt"
  "conclusion.txt"
)

# Loop to create 10 sample text files with different names
for i in {0..9}
do
  echo "${sample_paragraphs[$i]}" > "${file_names[$i]}"
done

echo "10 sample paragraph files with different names and content created."
