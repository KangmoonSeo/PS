## default.cpp, .vscode 구성요소, 자기 자신을 제외하고
## 실행 파일, 폴더 내 7일이 지난 파일을 삭제하는 script

## config
__PATH=~/PS/playground

## deletion
find ${__PATH} -mtime +7 -not -path "${__PATH}/remove.sh" -not -path "${__PATH}/default.cpp" -delete
find ${__PATH} -type f -not -name "*.*" -delete
find ${__PATH} -name 'tempCodeRunner*' -delete

## .zsh_history optimization
cat ~/.zsh_history | grep -v 'OneDrive' | grep -v '&&' | grep -v 'curl' | grep -v '{' | grep -v '(' | grep -v 'int' | tail -200 > ~/.zsh_history_temp
mv ~/.zsh_history_temp ~/.zsh_history
