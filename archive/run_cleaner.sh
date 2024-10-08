#!/bin/sh
## 디렉토리 내 실행 파일과 오래된 코드를 삭제하고 zsh 로그를 정리하는 스크립트

## set parameter
RELATIVE_DIR=`dirname "$0"`
cd $RELATIVE_DIR
SHELL_PATH=`pwd -P`

## clean directory
find ${SHELL_PATH} -mtime +7 -not -path "${SHELL_PATH}/run_cleaner.sh" -not -path "${SHELL_PATH}/main.cpp" -not -path "${SHELL_PATH}/Main.java" -delete
find ${SHELL_PATH} -type f -not -name "*.*" -delete
find ${SHELL_PATH} -type f -name "*.class" -delete
find ${SHELL_PATH} -name 'tempCodeRunner*' -delete

## optimize zsh_history
cat ~/.zsh_history | grep -v 'OneDrive' | grep -v '&&' | grep -v 'curl' | grep -v '{' | grep -v '(' | grep -v 'int' > ~/.zsh_history_temp
mv ~/.zsh_history_temp ~/.zsh_history
