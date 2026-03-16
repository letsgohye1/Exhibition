<h1 align="center">🌸 Unreal Engine Multiplayer Flower System 🏍</h1>

<p align="center">
Unreal Engine Listen Server 기반 멀티플레이어 동기화 시스템
</p>

<p align="center">
플레이어가 이동하면 꽃이 생성되고,<br>
오토바이의 색상과 조명을 실시간으로 변경 및 동기화하는 시스템입니다.
</p>

---

## 🎥 Demo

<p align="center">

![demo](demo/demo.gif)

</p>

---

## 🧰 Tech Stack

<p align="center">

Unreal Engine 5  
C++  
UE Replication  
RPC (Server Authority)  
Instanced Static Mesh (ISM)

</p>

---

## 🏗 System Architecture

본 시스템은 **Listen Server 구조**를 기반으로 합니다.

한 명의 플레이어가 **Client와 Server Host 역할을 동시에 수행**하며  
서버 권한(Server Authority)을 통해 상태를 관리하고 모든 클라이언트에 동기화합니다.

---

## 🌼 Flower Spawn System (ISM)

대량의 꽃을 **성능 저하 없이 생성하기 위해 Instanced Static Mesh 시스템을 사용했습니다.**

### Draw Call Optimization

기존 방식


Flower Actor × 수천 개
→ Draw Call 증가
→ FPS 감소


적용 방식


Single Instanced Static Mesh Component
→ 모든 꽃 Instance 관리


### 성능 이점

- Draw Call 수를 **수천 개 → 메시 타입당 1개로 감소**
- 밀집된 환경에서도 **높은 FPS 유지**

---

## 🔄 Late Join Synchronization

게임 도중 참여하는 플레이어도 동일한 환경을 볼 수 있도록 구현했습니다.

### Logic

모든 꽃 데이터는 **PlayerState Replicated Array**에 저장됩니다.


Flower Transform
Flower Type


### Process


1 Player Join
2 Replicated Array Sync
3 OnRep Trigger
4 Client Instance Spawn


### Result

Late Join 환경에서도 **동일한 월드 상태 유지**

---

## 🏍 Motorcycle Customization System

### Step 1 — Color Change (Server Authority)

클라이언트가 UI에서 색상을 선택하면  
Server RPC가 호출됩니다.


Client
↓
Server_SetBikeColor()
↓
Server updates BikeColor


---

### Step 2 — Property Replication

cpp
UPROPERTY(ReplicatedUsing=OnRep_BikeColor)
FLinearColor BikeColor;

서버에서 값이 변경되면
Unreal Network System이 모든 클라이언트에게 자동 전파합니다.

OnRep 처리

DynamicMaterial->SetVectorParameterValue("BodyColor", BikeColor);

---

### Step 3 — Light Synchronization

조명 상태 역시 Replication을 통해 동기화됩니다.
Variable
bBikeLightOn
OnRep 호출 시
LightComponent->SetVisibility()

모든 클라이언트에서 동시에 ON/OFF 적용

## ⚡ Performance Optimization </h6>
Rendering
Instanced Static Mesh 기반 대량 오브젝트 렌더링
높은 밀도의 환경에서도 높은 FPS 유지
Network
Tick 업데이트 대신 OnRep 기반 동기화
네트워크 대역폭 최소화

## 🚀 Key Features </h6>

✔ Unreal Engine Listen Server 기반 멀티플레이 시스템
✔ Instanced Static Mesh 기반 대량 오브젝트 최적화
✔ Replication + OnRep 기반 상태 동기화
✔ Late Join 환경 지원
✔ 서버 권한(Server Authority) 기반 시스템 설계

## 📌 Summary </h6>


이 프로젝트는 Unreal Engine의
Listen Server Architecture
Replication System
Instanced Static Mesh Optimization

을 활용하여 멀티플레이 환경에서 안정적인 동기화와 높은 렌더링 성능을 구현한 시스템입니다.


