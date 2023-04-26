## default.cpp, .vscode 구성요소, 자기 자신을 제외하고
## 실행 파일, 폴더 내 7일이 지난 파일을 삭제하는 script

find . -mtime +7 -not -path "./vscode" -not -path "./.vscode/*" -not -path "./remove.sh" -not -path "./default.cpp" -delete
find . -type f -not -name "*.*" -delete
find . -name 'tempCodeRunner*' -delete