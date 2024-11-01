# DataStructure

## 자료 구조의 종류

### 설명
- 자료구조를 이해하고 구현하는 저장소입니다.

|자료구조| 장점 | 단점 | 사용 예시 | 이미지 |
|--------|------|------|--------------------|------|
|vector| 빠른 임의 접근<br> 끝에서 빠른 삽입/삭제 | 중간 삽입/삭제가 느림 <br> 크기 조정 시 비용이 크다 | 아이템 목록 리스트 <br> 인벤토리 아이템 | <img src = "img/graph.png" width="200" height="100"> |
|list  | 빠른 삽입/삭제(어디서든)<br> 메모리 사용이 효율적 | 임의 접근이 느리다 | 큐 구현, AI 행동 목록 | --- |
|deque | 양쪽에서 빠른 데이터 삽입/삭제 <br> vector의 장점을 그대로 갖는다 | 중간 삽입이 느리다 <br> vector보다 메모리를 더 사용한다 | 명령어 히스토리 기능 구현 | -- |
|set   | 빠른 검색/삽입 <br> 자동 정렬 <br> 중복이 허용이 안됨 | 추가 메모리 사용 | 단일 아이템 구현 | --- |
|multiset | set과 동일하지만 중복이 허용됨 | set과 동일하다 | 아이템 드랍 테이블 id - droptable | --- |
|map| pair클래스를 이용해서 key와 value로 빠른 검색 사용 가능 | 삽입, 삭제시 rebuilding | 게임 설정 저장 구현 | --- |
|unorded set, map | hash로 구현한 자료구조, 매우 빠른 검색 | 정렬되지 않은 상태,추가 메모리 사용 | 게임에서 빠르게 검색이 필요한 경우에는 대부분 사용한다 | --- |
|Graph| 복잡한 관계를 표현할 수 있다 | 구현이 복잡하다 | 네비게이션(Navi) 길찾기, AI Behavior Tree | --- |
