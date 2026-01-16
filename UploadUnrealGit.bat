@echo off
REM ===============================================
REM Unreal 프로젝트 GitHub 업로드 자동 배치
REM ===============================================

REM 1️⃣ 프로젝트 폴더 이동
cd /d "C:\Users\Monstera\Desktop\ue\Exhibition"

REM 2️⃣ 기존 Git 제거 & 초기화
echo Removing existing Git repository...
git remote remove origin 2>nul
rmdir /s /q .git
git init

REM 3️⃣ .gitignore 생성
echo Creating .gitignore...
(
echo # Unreal Engine
echo Binaries/
echo DerivedDataCache/
echo Intermediate/
echo Saved/
echo .vs/
echo Backup/
echo Backup1/
echo *.sln
echo *.user
echo *.opensdf
echo *.sdf
echo *.VC.db
echo .vsconfig
) > .gitignore

REM 4️⃣ Git LFS 설치 및 트래킹
echo Setting up Git LFS...
git lfs install
git lfs track "*.uasset"
git lfs track "*.umap"
git add .gitattributes

REM 5️⃣ Git에 파일 추가 및 커밋
echo Adding files and committing...
git add .
git commit -m "Initial commit - Unreal project optimized for GitHub"

REM 6️⃣ 원격 GitHub 연결
echo Setting remote origin...
git remote add origin https://github.com/letsgohye1/Exhibition.git
git branch -M main

REM 7️⃣ 원격에 강제 푸시
echo Pushing to GitHub (may ask for login)...
git push -u origin main --force

echo ===============================================
echo ✅ Upload complete! Your Unreal project is on GitHub.
pause
