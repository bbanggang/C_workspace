# C 언어 스터디 협업 가이드

> **저장소 주소:** https://github.com/bbanggang/C_workspace  
> GitHub를 처음 사용하는 팀원을 위한 협업 시작 가이드입니다.  
> 초대 수락부터 브랜치 생성, 코드 공유까지 단계별로 설명합니다.

---

## 목차

1. [저장소 구조](#1-저장소-구조)
2. [협업자 초대 수락하기](#2-협업자-초대-수락하기)
3. [Git 설치 및 초기 설정](#3-git-설치-및-초기-설정)
4. [저장소 복사하기 (Clone)](#4-저장소-복사하기-clone)
5. [내 브랜치로 이동하기](#5-내-브랜치로-이동하기)
6. [매일 사용하는 작업 흐름](#6-매일-사용하는-작업-흐름)
7. [Pull Request (PR) 보내기](#7-pull-request-pr-보내기)
8. [유용한 Git 명령어 모음](#8-유용한-git-명령어-모음)
9. [자주 발생하는 오류와 해결법](#9-자주-발생하는-오류와-해결법)

---

## 1. 저장소 구조

```
C_workspace/
├── problem/          ← 공용 문제 폴더 (관리자가 업로드)
│   ├── chapter1/
│   └── docs/
├── 헌규/             ← 각자의 풀이 코드 폴더
├── 민서/
├── 승연/
└── 성진/
```

| 폴더 | 역할 | 수정 권한 |
|------|------|-----------|
| `problem/` | 공용 문제 저장소 | 관리자(헌규) |
| `본인이름/` | 개인 풀이 코드 | 본인만 |

> **규칙:** 본인 이름 폴더 안에만 코드를 작성하세요. 다른 사람의 폴더는 건드리지 않습니다.

---

## 2. 협업자 초대 수락하기

관리자가 GitHub에서 협업자 초대를 보내면 이메일로 알림이 옵니다.

### 초대 수락 방법

**방법 A — 이메일로 수락**
1. 가입한 이메일 받은편지함 확인
2. GitHub에서 온 메일 열기
3. **"View invitation"** 버튼 클릭
4. GitHub 페이지에서 **"Accept invitation"** 클릭

**방법 B — GitHub 직접 수락**
1. [https://github.com/bbanggang/C_workspace](https://github.com/bbanggang/C_workspace) 접속
2. 상단에 초대 알림 배너가 뜨면 **"Accept invitation"** 클릭

수락 후 저장소에 **Push 권한**이 생깁니다.

> **초대를 못 받았다면?** 관리자(헌규)에게 GitHub username을 알려주세요.

---

## 3. Git 설치 및 초기 설정

### Git 설치

**Windows:**
1. [https://git-scm.com/download/win](https://git-scm.com/download/win) 접속
2. **64-bit Git for Windows Setup** 다운로드 및 설치 (옵션은 기본값 유지)

설치 확인 (터미널 또는 Git Bash에서):
```bash
git --version
# git version 2.x.x 출력되면 성공
```

### 이름 & 이메일 설정 (최초 1회)

GitHub에 표시될 이름과 이메일을 등록합니다:
```bash
git config --global user.name "본인이름"
git config --global user.email "GitHub가입이메일@example.com"
```

설정 확인:
```bash
git config --global user.name
git config --global user.email
```

---

## 4. 저장소 복사하기 (Clone)

저장소를 내 컴퓨터로 가져오는 과정입니다. **최초 1회만** 실행합니다.

```bash
# 1. 원하는 폴더로 이동 (예: 바탕화면)
cd ~/Desktop

# 2. 저장소 복사
git clone https://github.com/bbanggang/C_workspace.git

# 3. 폴더로 진입
cd C_workspace
```

> Clone 후 GitHub 로그인 팝업이 뜨면 **"Sign in with your browser"** 버튼으로 인증하세요.

---

## 5. 내 브랜치로 이동하기

각자 **본인 이름의 브랜치**에서 작업합니다. `main` 브랜치에 직접 작업하지 않습니다.

| 팀원 | 브랜치 이름 |
|------|------------|
| 헌규 | `heongyu` |
| 민서 | `minseo` |
| 승연 | `seungyeon` |
| 성진 | `seongjin` |

```bash
# 원격 브랜치 목록 가져오기
git fetch

# 내 브랜치로 이동 (본인 브랜치 이름으로 변경)
git switch heongyu      # 헌규
git switch minseo       # 민서
git switch seungyeon    # 승연
git switch seongjin     # 성진
```

> 브랜치를 옮기면 터미널에 `(branchname)` 으로 현재 브랜치가 표시됩니다.  
> 항상 본인 브랜치에 있는지 확인 후 작업하세요.

---

## 6. 매일 사용하는 작업 흐름

```
작업 시작        →  git pull          (최신 상태로 업데이트)
코드 작성/수정
완료 후          →  git add .         (변경 파일 준비)
                 →  git commit -m ""  (변경 내용 저장)
                 →  git push          (GitHub에 올리기)
```

### 상세 명령어

```bash
# 1. 작업 시작 전 — 최신 상태 받아오기
git pull

# --- 본인 이름 폴더 안에서 코드 작성 ---

# 2. 변경 파일 확인 (습관 들이면 좋음)
git status

# 3. 변경 파일 스테이징
git add .              # 모든 변경 파일
git add 헌규/파일.c    # 특정 파일만

# 4. 커밋 메시지 작성
git commit -m "1장 버블정렬 풀이 추가"

# 5. GitHub에 업로드
git push
```

### 커밋 메시지 작성 예시

| 상황 | 커밋 메시지 |
|------|------------|
| 새 풀이 추가 | `문제 3번 풀이 추가` |
| 오류 수정 | `버블정렬 무한루프 오류 수정` |
| 코드 정리 | `변수명 정리 및 주석 추가` |

> 커밋 메시지는 나중에 어떤 작업을 했는지 기록으로 남으니 구체적으로 작성하세요.

---

## 7. Pull Request (PR) 보내기

`main` 브랜치는 **보호되어 있어** 직접 수정할 수 없습니다.  
본인 브랜치의 코드를 `main`에 합치려면 **PR(Pull Request)**을 통해야 합니다.

### PR 보내는 순서

**1단계 — 코드를 본인 브랜치에 push**
```bash
git push
```

**2단계 — GitHub에서 PR 생성**
1. [https://github.com/bbanggang/C_workspace](https://github.com/bbanggang/C_workspace) 접속
2. 상단에 뜨는 **"Compare & pull request"** 버튼 클릭  
   (없으면 **Pull requests** 탭 → **New pull request**)
3. 설정 확인:
   - `base`: `main` ← `compare`: 본인 브랜치
4. 제목과 설명 작성 후 **"Create pull request"** 클릭

**3단계 — 관리자 검토 후 병합**
- 관리자(헌규)가 코드를 확인하고 `main`에 병합합니다
- 병합 완료 알림은 이메일 또는 GitHub 알림으로 전달됩니다

> PR을 통해 코드 리뷰가 가능해서 실무와 동일한 방식으로 협업할 수 있습니다.

---

## 8. 유용한 Git 명령어 모음

### 상태 확인

```bash
git status                        # 변경된 파일 목록
git diff                          # 무엇이 변경됐는지 내용
git log --oneline                 # 커밋 기록 (한 줄 요약)
git log --oneline --graph --all   # 브랜치 포함 시각화
git branch -a                     # 모든 브랜치 목록
```

### 브랜치 이동

```bash
git switch 브랜치이름     # 브랜치 이동
git branch                # 현재 브랜치 확인
```

### 되돌리기

```bash
git restore --staged 파일이름   # 스테이징 취소 (add 취소)
git restore 파일이름            # 파일을 수정 전으로 되돌리기 (주의: 복구 불가)
```

### 원격 저장소

```bash
git remote -v    # 원격 저장소 주소 확인
git fetch        # 원격 변경사항 가져오기 (병합 안 함)
git pull         # 가져오기 + 내 브랜치에 병합
```

---

## 9. 자주 발생하는 오류와 해결법

### push가 안 될 때

```
error: failed to push some refs to 'origin'
```

원인: 팀원이 먼저 push해서 내 로컬이 뒤처진 상태  
해결:
```bash
git pull
git push
```

---

### "Please tell me who you are" 오류

```
Author identity unknown
```

원인: `user.name`, `user.email` 미설정  
해결:
```bash
git config --global user.name "이름"
git config --global user.email "이메일"
```

---

### git pull 후 에디터(vim)가 열릴 때

자동 병합 커밋 메시지 입력 화면입니다.  
`:wq` 입력 후 Enter를 누르면 저장 후 종료됩니다.

기본 에디터를 VS Code로 변경하려면:
```bash
git config --global core.editor "code --wait"
```

---

### 충돌(Conflict)이 발생했을 때

`git pull` 후 아래와 같은 표시가 파일 안에 나타납니다:

```
<<<<<<< HEAD
내가 작성한 코드
=======
팀원이 작성한 코드
>>>>>>> origin/main
```

해결 방법:
1. 해당 파일을 열어 `<<<<<<<`, `=======`, `>>>>>>>` 줄을 찾습니다
2. 남길 코드만 선택하고 나머지 표시줄 삭제
3. 저장 후 다시 커밋:
```bash
git add .
git commit -m "충돌 해결"
git push
```

---

## 주의사항

- `git push --force` 는 팀원의 코드를 덮어씌울 수 있으니 **절대 사용 금지**
- 항상 **본인 이름 브랜치**에서 작업하고, `main` 브랜치에는 직접 수정하지 않기
- 작업 시작 전 **반드시 `git pull`** 로 최신 상태 유지
- 코드는 **본인 이름 폴더** 안에만 작성하기

---

## 참고 자료

- Git 공식 문서: [https://git-scm.com/doc](https://git-scm.com/doc)
- GitHub 공식 가이드: [https://docs.github.com/ko](https://docs.github.com/ko)
- Git 브랜치 시각화 학습: [https://learngitbranching.js.org/?locale=ko](https://learngitbranching.js.org/?locale=ko)

---

> 궁금한 점은 저장소 관리자(헌규)에게 문의하거나 **Issues** 탭에 남겨주세요.
