# C_workspace — C 언어 스터디 협업 저장소

> 4명이 함께 C 언어를 공부하는 저장소입니다.  1
> 공용 문제 폴더(`problem`)에서 문제를 확인하고, 각자 이름 폴더에 풀이를 작성합니다.

---

## 멤버

| 이름 | 폴더 |
|------|------|
| 헌규 | `heonkyu/` |
| 민서 | `minseo/` |
| 승연 | `seungyeon/` |
| 성진 | `seongjin/` |

---

## 폴더 구조

```
C_workspace/
├── problem/              ← 공용 문제 폴더 (관리자만 수정)
│   ├── chapter1/
│   │   ├── problem01_arithmetic.c
│   │   └── ...
│   └── docs/
├── heonkyu/              ← 헌규 풀이 폴더
│   └── chapter1/
├── minseo/               ← 민서 풀이 폴더
│   └── chapter1/
├── seungyeon/            ← 승연 풀이 폴더
│   └── chapter1/
└── seongjin/             ← 성진 풀이 폴더
    └── chapter1/
```

---

## 브랜치 구조

```
main     ← 최종 코드 (직접 push 금지)
develop  ← 모두가 이 브랜치에서 작업
```

**규칙:**
- 항상 `develop` 브랜치에서 작업
- **본인 폴더에만** 코드 작성 (다른 사람 폴더 수정 금지)
- `main` 브랜치에는 직접 push 금지

---

## 목차

1. [처음 시작하기 (최초 1회)](#1-처음-시작하기-최초-1회)
2. [매일 하는 작업 루틴](#2-매일-하는-작업-루틴)
3. [다른 사람 코드 받아오기](#3-다른-사람-코드-받아오기)
4. [충돌 해결법](#4-충돌-해결법)
5. [자주 쓰는 명령어](#5-자주-쓰는-명령어)
6. [자주 발생하는 오류](#6-자주-발생하는-오류)

---

## 1. 처음 시작하기 (최초 1회)

### 1-1. GitHub 회원가입

1. [https://github.com](https://github.com) 접속 → 우상단 **Sign up**
2. 이메일, 비밀번호, 사용자 이름 설정
3. 이메일 인증 완료

> 관리자(헌규)에게 GitHub 아이디를 알려주면 저장소에 초대해 드립니다.

### 1-2. Git 설치

1. [https://git-scm.com/download/win](https://git-scm.com/download/win) 접속
2. **64-bit Git for Windows Setup** 다운로드 후 설치 (모든 옵션 기본값)

설치 확인:
```bash
git --version
# git version 2.x.x 출력되면 성공
```

### 1-3. Git 초기 설정 (이름 & 이메일 등록)

```bash
git config --global user.name "본인이름"
git config --global user.email "본인이메일@example.com"
```

### 1-4. 저장소 복제 (Clone)

```bash
# 저장소 복제
git clone https://github.com/bbanggang/C_workspace.git

# 폴더 진입
cd C_workspace
```

### 1-5. develop 브랜치로 이동

```bash
git checkout develop
```

브랜치 확인 (`*` 표시가 현재 위치):
```bash
git branch
# * develop  ← 이렇게 나오면 정상
```

---

## 2. 매일 하는 작업 루틴

```
작업 시작 전  →  git pull (최신 코드 받아오기)
코드 작성     →  본인 폴더에만 작성
작업 완료 후  →  add → commit → push
```

### 2-1. 작업 시작 전 — 최신 코드 동기화

```bash
git pull origin develop
```

### 2-2. 코드 작성

`problem/chapter1/` 폴더에서 문제를 확인하고,  
**본인 이름 폴더**에 풀이를 작성합니다.

예시 (헌규의 경우):
```
heonkyu/chapter1/problem01_arithmetic.c  ← 여기에 작성
```

### 2-3. 작업 완료 후 — 저장 및 업로드

```bash
# 변경된 파일 확인
git status

# 본인 폴더 스테이징
git add 본인이름/

# 커밋 (어떤 작업인지 구체적으로 작성)
git commit -m "chapter1: problem01 풀이 추가"

# develop에 푸시
git push origin develop
```

### 커밋 메시지 예시

| 나쁜 예 | 좋은 예 |
|---------|---------|
| `수정` | `chapter1: problem03 성적 계산 풀이 추가` |
| `업데이트` | `chapter2: problem05 포인터 오류 수정` |
| `asdf` | `chapter1: problem01~03 풀이 완료` |

---

## 3. 다른 사람 코드 받아오기

```bash
git pull origin develop
```

pull 후 로컬에 모든 팀원 폴더가 업데이트됩니다.

---

## 4. 충돌 해결법

같은 파일을 두 사람이 동시에 수정하면 충돌이 발생합니다.  
**각자 본인 폴더에만 작성하면 충돌이 거의 발생하지 않습니다.**

충돌 발생 시 파일 안에 아래 표시가 나타납니다:

```
<<<<<<< HEAD
내가 작성한 코드
=======
팀원이 작성한 코드
>>>>>>> origin/develop
```

해결 방법:
1. 해당 파일 열기
2. `<<<<<<<`, `=======`, `>>>>>>>` 표시줄 삭제
3. 남길 코드 선택 후 저장
4. 재커밋:

```bash
git add .
git commit -m "충돌 해결"
git push origin develop
```

---

## 5. 자주 쓰는 명령어

```bash
# 현재 상태 확인
git status

# 현재 브랜치 확인
git branch

# 커밋 기록 보기
git log --oneline --graph --all

# 변경 내용 확인
git diff

# 스테이징 취소
git restore --staged 파일이름

# 파일 수정 전으로 되돌리기 (주의: 복구 불가)
git restore 파일이름
```

---

## 6. 자주 발생하는 오류

### push가 거부될 때

```
error: failed to push some refs to 'origin'
```

팀원이 먼저 push한 상태. 해결:
```bash
git pull origin develop
# 충돌 없으면 자동 병합 후
git push origin develop
```

### 이름/이메일 미설정 오류

```
Author identity unknown
```

해결:
```bash
git config --global user.name "이름"
git config --global user.email "이메일"
```

### git pull 후 vim 편집기가 열릴 때

`:wq` 입력 후 Enter (저장하고 종료)

VS Code를 기본 에디터로 설정하려면:
```bash
git config --global core.editor "code --wait"
```

---

## 참고 자료

- Git 공식 문서: [https://git-scm.com/doc](https://git-scm.com/doc)
- GitHub 공식 가이드: [https://docs.github.com/ko](https://docs.github.com/ko)
- Git 브랜치 시각화 학습: [https://learngitbranching.js.org/?locale=ko](https://learngitbranching.js.org/?locale=ko)

---

> 궁금한 점은 저장소 Issues 탭에 남겨주세요.