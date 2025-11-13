#!/bin/bash

# VARIABLES
CURR_DIR="$(pwd)"

# --- SPINNER FUNCTION ---
# This function displays a spinner while a background process (PID) is running.
show_spinner(){
  local pid="${1}"
  local delay="0.1"
  local spinstr='\|/-'
  local i=0

  # loop while the process exits
  while ps -p "${pid}" > /dev/null; do
    i=$(( (i+1) % 4))
    # use $i for indexing spinstr
    printf "\r[%c] Initializing project..." "${spinstr:%i:1}"
    sleep "${delay}"
  done
  printf "\r                  \r" # Clear the spinner line}
}


# --- Project initialization ---

#  get the project name
read -p "Project name: " PROJECT_NAME
if [ -z "$PROJECT_NAME" ]; then
  echo "Error: Project name cannot be empty."
  exit 1
fi

# create directory
FOLDER_NAME="$(echo "${PROJECT_NAME}" | tr ' ' '-')" # replace spaces with hyphen in folder name
PROJECT_PATH="${CURR_DIR}/${FOLDER_NAME}"

echo ""
echo "creating and initializing project..."

# check if the folder already exists
if [ -d "${PROJECT_PATH}" ]; then
  echo "Error: ${PROJECT_PATH} already exists."
  exit 1
fi

# create the new dir
mkdir -p "$PROJECT_PATH"

# create the main.cpp file + boilerplate
cat <<EOCPP > "${PROJECT_PATH}/main.cpp"
#include <iostream>

int main(){
  std::cout<<"Hello, ${PROJECT_NAME}!" << std::endl;
  return 0;
}
EOCPP

# create read me file
README_FILE="${PROJECT_PATH}/README.md"

cat <<EOF > "$README_FILE"
# 🗓️ Day X: ${PROJECT_NAME}

## 🎯 Goal
*(Briefly describe the main purpose of this project.)*

## 🛠️ Tech Stack
* C++

## 💡 Key Learnings
*(Document 2-3 specific concepts, challenges, or techniques you mastered today.)*

## 🔗 Demo
* [Link to Live Demo (if applicable)]

## 🖼️ Screenshot

EOF

# --- Spinner Execution ---
# start the background task (sleep) and capture its PID
(sleep 3) &
spinner_pid=$!

# run the spinner function, passing the PID
show_spinner "${spinner_pid}"

# wait for the background task to complete
wait $spinner_pid 2>/dev/null

echo "project created and initialized successfully."
cd "${PROJECT_PATH}"
echo "Now in: $(pwd)"
echo "Happy Coding! 🎉"
