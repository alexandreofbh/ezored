//
//  ColorExtensions.swift
//  Sample-AppleWatch Extension
//
//  Created by ubook on 26/04/21.
//  Copyright © 2021 PRSoluções. All rights reserved.
//

import Foundation
import SwiftUI

extension View {
    @ViewBuilder func ignoreSafeArea() -> some View {
        if #available(watchOS 7, *) {
            self.ignoresSafeArea()
        } else {
            self
        }
    }
    
    @ViewBuilder func isHidden(_ hidden: Bool, remove: Bool = true) -> some View {
        if hidden {
            if !remove {
                self.hidden()
            }
        } else {
            self
        }
    }
}
