# C_workspace GitHub 협업 가이드

> 이 문서는 GitHub를 처음 사용하는 팀원을 위한 시작 가이드입니다.  
> GitHub 회원가입부터 이 저장소에 연결해 함께 작업하는 방법을 단계별로 설명합니다.

---

## 목차

1. [GitHub 회원가입](#1-github-회원가입)
2. [Git 설치](#2-git-설치)
3. [Git 초기 설정](#3-git-초기-설정)
4. [저장소 복사하기 (Clone)](#4-저장소-복사하기-clone)
5. [매일 사용하는 기본 흐름](#5-매일-사용하는-기본-흐름)
6. [주의사항](#6-주의사항)
7. [유용한 Git 명령어 모음](#7-유용한-git-명령어-모음)
8. [자주 발생하는 오류와 해결법](#8-자주-발생하는-오류와-해결법)

---

## 1. GitHub 회원가입

1. [https://github.com](https://github.com) 접속
2. 우상단 **Sign up** 클릭
3. 이메일 주소 입력 → **Continue**
4. 비밀번호 설정 (8자 이상, 숫자 또는 소문자 포함)
5. 사용자 이름(username) 설정 — 이후 `https://github.com/사용자이름` 주소로 사용됨
6. 이메일 인증 코드 입력 (가입한 이메일로 발송됨)
7. 설문 진행 후 가입 완료

> **팁:** username은 나중에 바꾸기 어려우니 신중하게 정하세요.

---

## 2. Git 설치

Git은 GitHub와 내 컴퓨터를 연결해주는 프로그램입니다.

### Windows
1. [https://git-scm.com/download/win](https://git-scm.com/download/win) 접속
2. **64-bit Git for Windows Setup** 다운로드
3. 설치 시 모든 옵션은 기본값으로 두고 **Next** → **Install**

### 설치 확인
터미널(PowerShell 또는 Git Bash)을 열고:
```bash
git --version
```
`git version 2.x.x` 처럼 버전이 출력되면 성공입니다.

---

## 3. Git 초기 설정

Git을 처음 설치하면 **이름과 이메일**을 등록해야 합니다.  
누가 어떤 코드를 작성했는지 기록하는 데 사용됩니다. (한 번만 설정하면 됩니다)

터미널에서 아래 명령어를 실행하세요. 큰따옴표 안의 내용을 본인 정보로 교체하세요:

```bash
git config --global user.name "홍길동"
git config --global user.email "your@email.com"
```

설정 확인:
```bash
git config --global user.name
git config --global user.email
```

---

## 4. 저장소 복사하기 (Clone)

이 저장소를 내 컴퓨터로 가져오는 과정입니다.

### 순서

**1. 저장소 URL 확인**

이 저장소의 주소:
```
https://github.com/bbanggang/C_workspace.git
```

**2. 원하는 폴더로 이동**

파일을 저장하고 싶은 위치로 이동합니다. 예를 들어 바탕화면에 저장하려면:
```bash
cd ~/Desktop
```

**3. Clone 실행**
```bash
git clone https://github.com/bbanggang/C_workspace.git
```

명령 실행 후 `C_workspace` 폴더가 생성됩니다.

**4. 폴더 진입**
```bash
cd C_workspace
```

**5. GitHub 로그인 (처음 한 번)**

`git push` 또는 `git pull` 시 GitHub 로그인 팝업이 뜹니다.  
**Sign in with your browser** 버튼을 누르면 브라우저에서 인증이 완료됩니다.

---

## 5. 매일 사용하는 기본 흐름

```
작업 시작 전       →   git pull     (최신 코드 받아오기)
코드 수정/작성
작업 완료 후       →   git add .    (변경 파일 준비)
                   →   git commit   (변경 내용 저장)
                   →   git push     (GitHub에 올리기)
```

### 명령어 실습

```bash
# 1. 작업 시작 전 — 팀원들의 최신 변경사항을 받아옴
git pull

# --- 코드 작성/수정 ---

# 2. 변경된 파일 확인 (선택사항이지만 습관 들이면 좋음)
git status

# 3. 변경 파일을 스테이징 (올릴 준비)
git add .          # 모든 변경 파일 추가
# 또는 특정 파일만 추가:
git add 파일이름.c

# 4. 커밋 — 변경 내용에 메시지 달기
git commit -m "어떤 작업을 했는지 간단히 설명"

# 5. GitHub에 올리기
git push
```

### 커밋 메시지 작성 예시

| 나쁜 예 | 좋은 예 |
|---------|---------|
| `수정` | `버블정렬 함수 오류 수정` |
| `업데이트` | `문제 3번 풀이 추가` |
| `asdf` | `README 설명 보완` |

커밋 메시지는 나중에 어떤 작업을 했는지 기록으로 남으니 구체적으로 적는 습관을 들이세요.

---

## 6. 주의사항

### 작업 전에 항상 git pull 먼저!

팀원이 파일을 수정했을 수 있습니다. `git pull`을 빠뜨리면 충돌(conflict)이 발생할 수 있습니다.

```bash
# 작업 시작할 때마다 습관처럼 실행
git pull
```

---

### 같은 파일을 동시에 수정하지 않기

두 명이 같은 파일의 같은 부분을 수정하면 **충돌(conflict)**이 발생합니다.  
작업 전에 팀원과 "나는 A 파일 맡을게" 처럼 역할을 나누는 것이 좋습니다.

---

### 충돌(Conflict)이 발생했을 때

`git pull` 또는 `git merge` 후 아래와 같은 표시가 파일 안에 나타납니다:

```
<<<<<<< HEAD
내가 작성한 코드
=======
팀원이 작성한 코드
>>>>>>> origin/main
```

해결 방법:
1. 해당 파일을 열어 `<<<<<<<`, `=======`, `>>>>>>>` 표시를 찾습니다
2. 남길 코드를 선택하고 나머지 표시줄을 삭제합니다
3. 저장 후 다시 커밋합니다:
```bash
git add .
git commit -m "충돌 해결"
git push
```

---

### .gitignore — 올리면 안 되는 파일 관리

비밀번호, API 키, 개인 설정 파일 등은 GitHub에 올라가면 안 됩니다.  
`.gitignore` 파일에 제외할 파일/폴더를 등록하면 자동으로 제외됩니다.

현재 제외 목록 예시:
```
.vscode/        # 개인 에디터 설정
*.exe           # 실행 파일
*.o             # 컴파일 중간 파일
```

---

### 절대 하면 안 되는 것

- `git push --force` — 팀원의 코드를 덮어씌울 수 있음 (관리자 허락 없이 금지)
- 커밋 없이 파일만 공유 — 변경 기록이 남지 않아 추적 불가
- `main` 브랜치에 직접 대규모 수정 — 가능하면 별도 브랜치 사용 권장

---

## 7. 유용한 Git 명령어 모음

### 상태 확인

```bash
# 현재 변경된 파일 목록 확인
git status

# 무엇이 변경됐는지 내용 확인
git diff

# 커밋 기록 확인 (한 줄 요약)
git log --oneline

# 커밋 기록 + 그래프 시각화
git log --oneline --graph --all
```

### 되돌리기

```bash
# 스테이징 취소 (add 취소)
git restore --staged 파일이름

# 파일 수정 전으로 되돌리기 (주의: 되돌리면 복구 불가)
git restore 파일이름

# 마지막 커밋 메시지 수정 (push 전에만)
git commit --amend -m "수정된 메시지"
```

### 브랜치

```bash
# 브랜치 목록 확인
git branch

# 새 브랜치 만들기
git branch 브랜치이름

# 브랜치 이동
git checkout 브랜치이름
# 또는 (최신 방식)
git switch 브랜치이름

# 브랜치 만들고 바로 이동
git checkout -b 브랜치이름

# 브랜치 병합 (main으로 이동 후)
git merge 브랜치이름
```

### 원격 저장소

```bash
# 원격 저장소 주소 확인
git remote -v

# 원격에서 변경사항만 가져오기 (병합 안 함)
git fetch

# 가져오기 + 병합
git pull
```

---

## 8. 자주 발생하는 오류와 해결법

### push가 안 될 때

```
error: failed to push some refs to 'origin'
```

원인: 팀원이 먼저 push해서 내 로컬이 뒤처진 상태  
해결:
```bash
git pull
# 충돌 없으면 자동 병합됨
git push
```

---

### Please tell me who you are

```
Author identity unknown
```

원인: `user.name`, `user.email`이 설정되지 않음  
해결:
```bash
git config --global user.name "이름"
git config --global user.email "이메일"
```

---

### git pull 후 에디터(vim)가 열릴 때

자동 병합 커밋 메시지 입력 화면입니다.  
`:wq` 입력 후 Enter를 누르면 저장하고 빠져나옵니다.

vim이 불편하다면 기본 에디터를 변경할 수 있습니다:
```bash
# VS Code를 기본 에디터로 설정
git config --global core.editor "code --wait"
```

---

### SSL 인증서 오류

```
SSL certificate problem
```

해결:
```bash
git config --global http.sslVerify false
```

---

## 참고 자료

- Git 공식 문서: [https://git-scm.com/doc](https://git-scm.com/doc)
- GitHub 공식 가이드: [https://docs.github.com/ko](https://docs.github.com/ko)
- Git 시각화 학습 (브랜치 이해에 유용): [https://learngitbranching.js.org/?locale=ko](https://learngitbranching.js.org/?locale=ko)

---

> 궁금한 점은 저장소 관리자에게 문의하거나 Issues 탭에 남겨주세요.
